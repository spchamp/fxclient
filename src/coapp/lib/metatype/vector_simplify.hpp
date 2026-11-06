/**
 *
 * This source is in the public domain.  It is distributed in the hope
 * that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#pragma once

#include <cstddef>
#include <utility>

#include <boost/mpl/at.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/vector.hpp>

namespace coapp::lib::metatype {

namespace mpl = boost::mpl;

/// @brief unspecialized `vector_simplify` template
template <typename S, typename = void>
struct vector_simplify {};

/// @brief transform a sequence-like type `S`, under boost MPL,
/// into a boost MPL vector type, for all elements within a
/// provided index sequence `N...`
template <typename S, std::size_t... N>
struct vector_simplify<S, std::index_sequence<N...>>
    : mpl::vector<typename mpl::at_c<S, N>::type...>::type {};

/// @brief transform a sequence-like type `S`, under boost MPL,
/// into a boost MPL vector type, for all elements within `S`
template <typename S>
    requires (mpl::is_sequence<S>::value)
struct vector_simplify<S>
    : vector_simplify<S, std::make_index_sequence<mpl::size<S>::value>> {};

}  // namespace coapp::lib::metatype
