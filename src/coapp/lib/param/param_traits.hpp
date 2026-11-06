
// type traits for applications of boost parameter

#pragma once

#include <boost/parameter/binding.hpp>
#include <boost/parameter/is_argument_pack.hpp>
#include <boost/type_traits/is_same.hpp>

#include <coapp/lib/unspecified.hpp>

namespace coapp::lib::param {

template <typename T>
using argument_pack_p = boost::parameter::is_argument_pack<T>;

template <typename T>
concept argument_pack = argument_pack_p<T>::value;

template <typename Params, typename Tag>
struct param_unspecified_p : unspecified_t {};

template <typename Params, typename Tag>
requires (argument_pack<Params>)
struct param_unspecified_p<Params, Tag>
    : boost::is_same<
            typename boost::parameter::binding<Params, Tag, unspecified_t>::type, unspecified_t
      >::type {};

template <typename Params, typename Tag>
concept param_unspecified = param_unspecified_p<Params, Tag>::value;


template <typename Params, typename Tag>
requires (!param_unspecified<Params, Tag>)
using param_bound_t = typename boost::parameter::binding<Params, Tag, unspecified_t>::type;


}  // namespace coapp::lib::param
