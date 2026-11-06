/**
 *
 * This source is in the public domain.  It is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#pragma once

#include <type_traits>
#include <variant>

#include <boost/type_index/ctti_type_index.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/unique.hpp>

#include <coapp/lib/metatype/vector_simplify.hpp>
#include <coapp/lib/metatype/template_apply.hpp>

namespace coapp::lib::metatype {

namespace mpl = boost::mpl;
namespace mph = boost::mpl::placeholders;

template <typename... T>
struct variant_derive {

    using types_in       = typename mpl::vector<T...>::type;

    using typeindex_type = boost::typeindex::ctti_type_index;

    template <typename L, typename R>
    struct sort_op {
        // Characteristics of this sort_op:
        // - Strict ordering for std::monostate is not dependent on
        //   the compiler
        // - Strict ordering for types of different sizes (in this compiler)
        //   is not otherwise dependent on the compiler
        // - Otherwise: The type index before() op may depend on the
        //   compiler's type name, for each of L and R
        static constexpr bool value =
              (std::is_same_v<L, std::monostate> || (sizeof(L) < sizeof(R))) ?
                    true :
                    ((std::is_same_v<R, std::monostate>
                      || (sizeof(L) > sizeof(R))) ?
                           false :
                           typeindex_type::template type_id<L>().before(
                                 typeindex_type::template type_id<R>()));
    };

    using types_out = typename mpl::
          unique<typename mpl::sort<types_in, sort_op<mph::_1, mph::_2>>::type,
                 boost::is_same<mph::_1, mph::_2>>::type;

    using type = typename template_apply<std::variant, types_out>::type;
};

}  // namespace coapp::lib::metatype
