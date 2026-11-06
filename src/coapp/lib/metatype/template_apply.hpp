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
#include <boost/mpl/identity.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/size.hpp>

namespace coapp::lib::metatype {

namespace mpl = boost::mpl;

template <template <typename...> typename Mt, typename S, typename = void>
struct template_apply {};

template <template <typename...> typename Mt, typename S, std::size_t... N>
struct template_apply<Mt, S, std::index_sequence<N...>>
    : mpl::identity<Mt<typename mpl::at_c<S, N>::type...>> {};

template <template <typename...> typename Mt, typename S>
    requires (mpl::is_sequence<S>::value)
struct template_apply<Mt, S>
    : template_apply<Mt, S, std::make_index_sequence<mpl::size<S>::value>> {};

template <template <typename...> typename Mt, typename... T>
struct template_apply<Mt, std::tuple<T...>> : mpl::identity<Mt<T...>> {};


}  // namespace coapp::lib::metatype
