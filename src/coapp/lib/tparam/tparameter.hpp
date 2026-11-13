#pragma once

#include <boost/mpl/not.hpp>
#include <type_traits>

#include <boost/mpl/fold.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>

#include <coapp/lib/metatype/sequence_contains.hpp>

namespace coapp::lib::tparam {

// towards an alternative to the template parameter constructs
// provided with boost parameter, mainly using C++20 concepts
// and boost MPL
//
// While this was inspired by template parameter constructs
// from boost parameter, this does not emulate all characteristics
// of the boost parameter API:
//
// - this relies on the direct definition of a struct type for
//   representing each template parameter, without the use of
//   an intermediate macro to define such struct.
//
// - no qualifier for a bound parameter type,
//   instead favoring the use of C++20 concepts
//   to establish type constraints.
//
// - no intermediate tag types.
//
//   It's assumed that the template type `tparameter<Impl>` will be implemented
//   generally as `struct S : tparameter<S>` such that the resulting types `S` and
//   `tparameter<S>` may each serve as a desginating type, without requiring a
//   supplemental `tag` member type.
//
// - no parameter name strings
//
//   These template parameter types are essentially baked into the compiled code.
//   It's expected that this may provide a negligible opportunity for interaction
//   with external type systems, other than through any read-only representation of
//   the hard-coded types. In such case, a demangled type identity may be sufficient
//   for identifying any template parameter type.
//
// - For an ordered set of bindings for these template parameter types, the
// templates
//   providing iteration across the set will generally not fail if some type in the
//   set is not a template parameter binding type. These iteration templates would
//   include:
//
//   - `tparameter_present_p` / `tparameter_present_v`, applicable for any template
//     parameter "flag type" `T` or any template parameter type `P`. For the `T`
//     case, will resolve to `std::true_type` when `T` is present within the
//     provided `Param...` types. For the `P` case, will resolve to `std::true_type`
//     when a template parameter binding type for `P` is present within the provided
//     `Param...` types
//
//  - `tparameter_optional`/`tparameter_optional_t` accepting a default type `U`
//     for a template parameter type `P`, then resolving to the bound type
//     for `P`, or the type `U` when no binding type is provided in the  `Param...`
//     types.
//
//  - `tparameter_required`/`tparameter_required_t` requiring that a binding for
//     the template parameter `P` is present within the set of `Param...` types,
//     then resolving to the bound type for `P` within the provided `Param...`
//     types.

namespace mpl = boost::mpl;
namespace mph = boost::mpl::placeholders;

// fwd types, concepts

template <typename Impl>
struct tparameter;

template <typename T>
concept is_tparameter = requires (T that) {
                            [](tparameter<T>) {
                            }(that);
                        };

template <typename Impl, typename T>
    requires (is_tparameter<Impl>)
struct tparameter_binding;

/// @brief base class for template parameter types
///
/// @tparam Impl the implementing template parameter type
///
/// @example
/// ```cpp
/// struct serial_type : tparameter<serial_type> {};
///
/// template<typename... P>
/// struct data {
///   using serial_t = tparameter_optional_t<serial_type, int, P...>;
/// };
///
/// using size_t_impl = data<serial_type::bind<std::size_t>>;
/// using size_t_serial = typename size_t_impl::serial_t; // size_t
///
/// using default_impl = data<>;
/// using default_serial = typename default_impl::serial_t; // int
/// ```
template <typename Impl>
struct tparameter {
    using type = Impl;

    template <typename T>
    using bind = tparameter_binding<Impl, T>;
};

/// @brief template for binding a template parameter to some type
///
/// @tparam Impl the template parameter type
/// @tparam T the bound type
template <typename Impl, typename T>
    requires (is_tparameter<Impl>)
struct tparameter_binding {
    using param_type = Impl;
    using type       = T;
};

template <typename T>
concept is_tparameter_binding =
      is_tparameter<typename T::param_type>
      && requires (T that) {
             []<typename Impl, typename U>(tparameter_binding<Impl, U>) {
             }(that);
         };

template <typename T>
struct tparameter_binding_p : std::false_type {};

template <typename T>
    requires (is_tparameter<typename T::param_type>
              && requires (typename T::type) { true; })
struct tparameter_binding_p<T> : std::true_type {};

template <typename T>
    requires (tparameter_binding_p<T>::value)
struct tparameter_bound_type : std::type_identity<typename T::type> {};

template <typename Param, typename... P>
struct tparameter_bound_p : std::false_type {};

template <typename Param, typename... P>
    requires (sizeof...(P) > 0 && is_tparameter<Param>)
struct tparameter_bound_p<Param, P...> {
    using provided_types = typename mpl::vector<P...>::type;

    template <typename U>
    struct _match_p : std::false_type {};

    template <typename U>
        requires (is_tparameter_binding<U>)
    struct _match_p<U> : std::is_same<typename U::param_type, Param>::type {};

    template <typename TMatched, typename T>
    struct match_op {
        // the _match_p specialization here may need to be expanded
        // not until the match_op type is instantiated. This could
        // probably not be expressed within the base class to match_op.
        using type = typename mpl::if_<TMatched, TMatched,
                                       typename _match_p<T>::type>::type;
    };

    using type = typename mpl::fold<provided_types, std::false_type,
                                    match_op<mph::_1, mph::_2>>::type;

    static constexpr bool value = type::value;
};

namespace tdetail {

///
/// @brief common base type for tparameter_optional and tparameter_required
/// templates
///
template <typename Param, typename Default, typename... P>
    requires (is_tparameter<Param>)
struct tparameter_resolve {
    using provided_types = typename mpl::vector<P...>::type;

    template <typename Prefer, typename Provided>
    struct fold_op {
        template <typename T>
        struct type_op : std::type_identity<Prefer> {};

        template <typename T>
            requires (tparameter_binding_p<T>::value)
        struct type_op<T> {
            using type =
                  typename mpl::if_<std::is_same<typename T::param_type, Param>,
                                    typename tparameter_bound_type<T>::type,
                                    Prefer>::type;
        };

        using type = typename type_op<Provided>::type;
    };

    using type = typename mpl::fold<provided_types, Default,
                                    fold_op<mph::_1, mph::_2>>::type;
};

};  // namespace tdetail

template <typename Param, typename Default, typename... P>
    requires (is_tparameter<Param>)
struct tparameter_optional : tdetail::tparameter_resolve<Param, Default, P...> {};

template <typename Param, typename Default, typename... P>
    requires (is_tparameter<Param>)
using tparameter_optional_t =
      typename tparameter_optional<Param, Default, P...>::type;

template <typename Param, typename... P>
    requires (is_tparameter<Param> && tparameter_bound_p<Param, P...>::value)
struct tparameter_required : tdetail::tparameter_resolve<Param, void, P...> {};

template <typename Param, typename... P>
    requires (is_tparameter<Param>)
using tparameter_required_t = typename tparameter_required<Param, P...>::type;

template <typename Param, typename... P>
struct tparameter_present_p : std::false_type {};

template <typename T, typename... P>
    requires (sizeof...(P) > 0 && !is_tparameter<T>)
struct tparameter_present_p<T, P...>
    : metatype::sequence_contains_op<typename mpl::vector<P...>::type, T>::type {};

template <typename Param, typename... P>
    requires (sizeof...(P) > 0 && is_tparameter<Param>)
struct tparameter_present_p<Param, P...> : tparameter_bound_p<Param, P...>::type {};

template <typename Param, typename... P>
static constexpr bool tparameter_present_v =
      tparameter_present_p<Param, P...>::type::value;

}  // namespace coapp::lib::tparam
