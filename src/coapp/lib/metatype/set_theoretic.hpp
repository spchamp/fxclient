#pragma once

#include <boost/mpl/fold.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/vector.hpp>

#include <coapp/lib/metatype/vector_simplify.hpp>
#include <coapp/lib/metatype/sequence_contains.hpp>

namespace coapp::lib::metatype {

namespace mpl = boost::mpl;
namespace mph = boost::mpl::placeholders;

using coapp::lib::metatype::vector_simplify;
using coapp::lib::metatype::sequence_contains_op;

template <typename LS, typename RS>
struct union_op {};

template <typename LS, typename RS>
    requires (mpl::is_sequence<LS>::value && mpl::is_sequence<RS>::value)
struct union_op<LS, RS>
    : vector_simplify<typename mpl::joint_view<
            LS, typename mpl::fold<
                      RS, mpl::vector0<>,
                      mpl::if_<sequence_contains_op<LS, mph::_2>, mph::_1,
                               mpl::joint_view<mph::_1, mpl::vector1<mph::_2>>>
                >::type
      >::type>::type {};

template <typename LS, typename RS>
struct intersection_op {};

template <typename LS, typename RS>
    requires (mpl::is_sequence<LS>::value && mpl::is_sequence<RS>::value)
struct intersection_op<LS, RS>
    : vector_simplify<typename mpl::fold<
            RS, mpl::vector0<>,
            mpl::if_<sequence_contains_op<LS, mph::_2>,
                     mpl::joint_view<mph::_1, mpl::vector1<mph::_2>>, mph::_1>
      >::type>::type {};

template <typename LS, typename RS>
struct difference_op {};

template <typename LS, typename RS>
    requires (mpl::is_sequence<LS>::value && mpl::is_sequence<RS>::value)
struct difference_op<LS, RS>
    : vector_simplify<typename mpl::fold<
            LS, mpl::vector0<>,
            mpl::if_<sequence_contains_op<RS, mph::_2>, mph::_1,
                     mpl::joint_view<mph::_1, mpl::vector1<mph::_2>>>
      >::type>::type {};

}  // namespace coapp::lib::metatype
