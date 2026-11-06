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
#include <boost/mpl/find.hpp>
#include <boost/mpl/end.hpp>
#include <boost/mpl/is_sequence.hpp>

namespace coapp::lib::metatype {

namespace mpl = boost::mpl;

template <typename S, typename T>
struct sequence_contains_op {};

/// implementation note: For mpl sequence support with std::tuple
/// types, see also: Boost Fusion's adapted types
template <typename S, typename T>
    requires(mpl::is_sequence<S>::value)
struct sequence_contains_op<S, T>
    : std::negation<std::is_same<typename mpl::find<S, T>::type,
                                 typename mpl::end<S>::type>>::type {};


template <typename S, typename T>
concept sequence_contains = sequence_contains_op<S, T>::value;


}  // namespace coapp::aux::metatype
