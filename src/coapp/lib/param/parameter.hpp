#pragma once

#include <boost/parameter.hpp>
#include <boost/mpl/identity.hpp>

#include <coapp/lib/LText.hpp>
#include <coapp/lib/unspecified.hpp>
#include <coapp/lib/param/param_traits.hpp>

#include <type_traits>

namespace coapp::lib::param {

namespace mpl    = boost::mpl;
namespace bparam = boost::parameter;

/// forward decl
template <typename Impl, LText Name, typename Qualifier>
struct parameter;

namespace detail {

template <typename Param, typename Impl, LText Name,
          typename Qualifier = bparam::forward_reference>
struct param_tag {
    using parameter      = Param;  // added
    using implementation = Impl;   // added

    using _  = bparam::value_type<mpl::_2, implementation, bparam::void_>;
    using _1 = _;

    template <typename ArgumentPack>
        requires (argument_pack<ArgumentPack>)
    using binding_fn =
          typename bparam::binding<ArgumentPack, Param, bparam::void_>::type;

    template <typename ArgumentPack>
        requires (argument_pack<ArgumentPack>)
    using fn =
          typename bparam::value_type<ArgumentPack, Param, bparam::void_>::type;

    using qualifier = Qualifier;

    static constexpr char const* keyword_name() noexcept { return Name.cdata(); }
};

}  // namespace detail

///@brief Structural Parameter type
///
/// This generally emulates the behaviors of boost parameter's
/// `BOOST_PARAMETER_NAME` macro, by introducing a structured template
/// type for purpose of parameter identity.
///
///@section usage General Usage
///
/// For a structured type `struct P : parameter<P, "P"> {}`:
///
/// - The static data member `P::keyword`  may be applied for purpose of
/// parameter assignment,
///   mainly as when constructing a bost parameter  _argument pack_ for
///   some function. This same `P::keyword` object may be used within the
///   respective function - generally together with the argument pack's
///   `operator[]` - for purpose of retrieving the value assigned for the
///   respective parameter. (This value access will be constrained per the
///   `Qualifier` type provided when the `parameter` type was defined).
///
/// - The member type `P::tag`  may be used for purpose of reflection onto
/// the tags specified
///   within a boost parameter _argument pack_. (Albeit, in this case, the
///   type `P` would not participate directly within the construction of
///   the _argument pack_ type.)
///
/// - The function `P::tag::keyword_name()` may be used to retrieve the
/// assigned name of the
///   respective parameter keyword.  This may be generally compatible with
///   parameter tags defined using the `BOOST_PARAMETER_NAME` macro.
///   Alternately, the static data member `P::name` would provide the
///   assgigned name of the parameter, within an `std::string_view`.
///
///@section tag-traits Tag Traits
///
/// In this `parameter` template structure, the `tag` member type will be
/// defined as to have the member types `parameter` and `implementation`.
/// These types would each represent a sort of extension after parameter
/// tags defined with the `BOOST_PARAMETER_NAME` macro.
///
/// From a perspective of a `parameter` type `P`, as well as its member
/// type `P::tag`:
/// - The type `P::tag::parameter` would represent the parameter type `P`
/// - The type `P::tag::implementation` would represent the tag type
/// `P::tag`
///
/// These type traits may be applied for general purpose of reflection,
/// such as for the set of parameter tags that would be provided in a
/// boost parameter _argument pack_.
///
///@section traits-param Type Traits: Parameter from Tag
///
/// For compatibility with parameter tags defined with the
/// `BOOST_PARAMETER_NAME` macro, the type `P::tag::parameter` is
/// supplemented with the top-level template type, `tag_param<T>`.
///
/// - For a parameter tag `T1` defined with the `BOOST_PARAMETER_NAME`
/// macro, the type
///   `tag_param<T1>::type` would represent the type `unspecified_t`.
///
/// - For a parameter tag `T2 = P::tag` defined within a `parameter` type
/// `P`, the
///   type `tag_param<T2>::type` would represent the type `P`.
///
///@section caveats Caveats
///
/// For purpose of compatibility with boost parameter, this assumes that
/// the boost parameter headers will have access to boost mp11.
///
/// The `Qualifier` template parameter should generally be constrained to
/// the set of _qualifier types_ supported in boost parameter. This type
/// will affect how any values are accessed from a boost parameter
/// _argument pack_ providing any binding for the respective parameter
/// tag.
///
///@tparam Impl The type implementing this `parameter` class template
///@tparam Name A string-like name of the parameter, generally for purpose
/// of reflection
///@tparam Qualifier The _parameter qualifier_ type for the parameter's
///`tag` type
///
///
template <typename Impl, LText Name, typename Qualifier = bparam::forward_reference>
struct parameter {
    struct tag : detail::param_tag<Impl, tag, Name, Qualifier> {};

    using category_tag = unspecified_t;

    static constexpr bparam::keyword<tag> const& keyword =
          bparam::keyword<tag>::instance;

    static constexpr std::string_view name = Name.to_view();

    ///@brief convenience type for determing whether a parameter's tag
    /// has been specified within some argument pack
    ///
    ///@section limitations Known Limitations
    ///
    /// This would not be immediately compatible with parameter tags that
    /// would defined as with the macro `BOOST_PARAMETER_NAME`. For these
    /// cases, the template type `param_unspecified_p` may be used
    /// directly, provided with the namespace-qualified tag for the
    /// respective parameter.
    template <typename ArgumentPack>
        requires (argument_pack<ArgumentPack>)
    using bound_p =
          std::negation<typename param_unspecified_p<ArgumentPack, tag>::type>;
};

template <typename T>
struct tag_param : mpl::identity<unspecified_t> {};

template <typename T>
    requires (std::is_same_v<typename T::parameter::tag, T>)
struct tag_param<T> : mpl::identity<typename T::parameter> {};

template <typename T>
struct tag_category : mpl::identity<unspecified_t> {};

template <typename T>
    requires (std::is_same_v<typename T::parameter::tag, T>)
struct tag_category<T> : mpl::identity<typename T::category> {};

}  // namespace coapp::lib::param
