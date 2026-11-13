#pragma once

// include this first
#include <fxsupport/serial_macros.hpp>

#include <array>                             // IWYU pragma: keep
#include <cstddef>                           // IWYU pragma: keep
#include <string_view>                       // IWYU pragma: keep
#include <type_traits>                       // IWYU pragma: keep
#include <utility>                           // IWYU pragma: keep
#include <fxsupport/serial_enum_detail.hpp>  // IWYU pragma: keep

#include <fxsupport/SerialEnum.hpp>
#include <fxsupport/SerialMetadata.hpp>

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>

#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/array/to_seq.hpp>
#include <boost/preprocessor/array/size.hpp>

#include <boost/preprocessor/comparison/greater.hpp>

#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/control/if.hpp>

#include <boost/preprocessor/facilities/check_empty.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/facilities/identity.hpp>

#include <boost/preprocessor/list/adt.hpp>

#include <boost/preprocessor/logical/not.hpp>

#include <boost/preprocessor/repetition/enum.hpp>

#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/size.hpp>

#include <boost/preprocessor/variadic/to_array.hpp>


#ifndef SERIAL_PREFIX
#    define SERIAL_PREFIX Serial
#endif

#ifndef SERIAL_ENUM_DEFAULT_BASE
#    define SERIAL_ENUM_DEFAULT_BASE int
#endif

#define _SERIAL_ENUM_INLINE_P(_memb) BOOST_PP_NOT(BOOST_PP_ARRAY_SIZE(_memb))

#define _SERIAL_ENUM_MEMB_MEMB(_n, _defs)                                          \
    BOOST_PP_TUPLE_ELEM(0, BOOST_PP_ARRAY_ELEM(_n, _defs))

#define _SERIAL_ENUM_ENUM_MEMQ(_z, _n, _data)                                      \
    BOOST_PP_LIST_FIRST(_data)::_SERIAL_ENUM_MEMB_MEMB(_n,                         \
                                                       BOOST_PP_LIST_REST(_data))

#define _SERIAL_ENUM_MEMB_VALUE(_n, _defs)                                         \
    BOOST_PP_IF(BOOST_PP_GREATER(                                                  \
                      BOOST_PP_TUPLE_SIZE(BOOST_PP_ARRAY_ELEM(_n, _defs)), 1),     \
                BOOST_PP_TUPLE_ELEM(1, BOOST_PP_ARRAY_ELEM(_n, _defs)), _n)

/// deferring the expansion of BOOST_PP_TUPLE_ELEM(2, ...) here
#define _SERIAL_ENUM_MEMB_NAME(_n, _defs)                                          \
    BOOST_PP_EXPAND(BOOST_PP_IF(                                                   \
          BOOST_PP_GREATER(BOOST_PP_TUPLE_SIZE(BOOST_PP_ARRAY_ELEM(_n, _defs)),    \
                           2),                                                     \
          BOOST_PP_TUPLE_ELEM, BOOST_PP_STRINGIZE)                                 \
                          BOOST_PP_IF(BOOST_PP_GREATER(                            \
                                            BOOST_PP_TUPLE_SIZE(                   \
                                                  BOOST_PP_ARRAY_ELEM(_n, _defs)), \
                                            2),                                    \
                                      (2, BOOST_PP_ARRAY_ELEM(_n, _defs)),         \
                                      (_SERIAL_ENUM_MEMB_MEMB(_n, _defs))))


#define _SERIAL_ENUM_ENUM_VALUE(_z, _n, _data)                                     \
    static_cast<underlying_type>(_SERIAL_ENUM_ENUM_MEMQ(_z, _n, _data))

#define _SERIAL_ENUM_ENUM_NAME(_z, _n, _defs) _SERIAL_ENUM_MEMB_NAME(_n, _defs)

#define _SERIAL_ENUM_NAME_MEMBER(_z, _n, _data)                                    \
    {_SERIAL_ENUM_MEMB_NAME(_n, BOOST_PP_LIST_REST(_data)),                        \
     _SERIAL_ENUM_ENUM_MEMQ(_z, _n, _data)}

#define _SERIAL_ENUM_MEMBER_NAME(_z, _n, _data)                                    \
    {_SERIAL_ENUM_ENUM_MEMQ(_z, _n, _data),                                        \
     _SERIAL_ENUM_MEMB_NAME(_n, BOOST_PP_LIST_REST(1, _data))}

#define _SERIAL_ENUM_BASE(_info)                                                   \
    BOOST_PP_IF(BOOST_PP_AND(BOOST_PP_TUPLE_SIZE(_info),                           \
                             BOOST_PP_NOT(BOOST_PP_CHECK_EMPTY(                    \
                                   BOOST_PP_TUPLE_ELEM(0, _info)))),               \
                BOOST_PP_TUPLE_ELEM(0, _info), SERIAL_ENUM_DEFAULT_BASE)

#define _SERIAL_ENUM_MEMB_DEFINE(_z, _n, _defs)                                    \
    _SERIAL_ENUM_MEMB_MEMB(_n, _defs) = _SERIAL_ENUM_MEMB_VALUE(_n, _defs)

#define _SERIAL_ENUM_ENUM_DEFINE(_name, _info, _memb)                              \
    enum class _name : _SERIAL_ENUM_BASE(_info){BOOST_PP_ENUM(                     \
          BOOST_PP_ARRAY_SIZE(_memb), _SERIAL_ENUM_MEMB_DEFINE, _memb)};

#define _SERIAL_ENUM_MODEL_NAME(_name, _info)                                      \
    _SERIAL_METADATA_NAME(_name, _SERIAL_POP_TUPLE(_info))

// for some enum definitions, it may be effectively impossible to compile
// the name->member map under a constexpr evalution. This appears to be
// related to how the hash functions are implemented when compiled
// as constexpr, when using boost hash2 within the hash op.
//
// A `const inline` form may be sufficient for the name->value mapping container 
// here, insofar as for purpose of name->value translation at runtime. In this
// case, the mapping can use an std::unordered_map
//
// Short of requiring a hash call, compile-time translations may make reference
// to the constexpr name, member, and value arrays.

#define _SERIAL_ENUM_DEFS(_name, _info, _memb)                                     \
    using char_type       = char;                                                  \
    using name_type       = std::basic_string_view<char_type>;                     \
    using underlying_type = std::underlying_type_t<_name>;                         \
                                                                                   \
    static constexpr std::size_t count{                                            \
          BOOST_PP_CAT(BOOST_PP_ARRAY_SIZE(_memb), U)};                            \
    static constexpr auto index = std::make_index_sequence<count>();               \
                                                                                   \
    static constexpr std::array<_name, count>           members{BOOST_PP_ENUM(     \
          BOOST_PP_ARRAY_SIZE(_memb), _SERIAL_ENUM_ENUM_MEMQ, (_name, _memb))};    \
                                                                                   \
    static constexpr std::array<underlying_type, count> values{BOOST_PP_ENUM(      \
          BOOST_PP_ARRAY_SIZE(_memb), _SERIAL_ENUM_ENUM_VALUE, (_name, _memb))};   \
                                                                                   \
    static constexpr std::array<name_type, count>       names{BOOST_PP_ENUM(       \
          BOOST_PP_ARRAY_SIZE(_memb), _SERIAL_ENUM_ENUM_NAME, _memb)};             \
                                                                                   \
    using name_member_map_t =                                                      \
          MODEL_NS::detail::name_member_map_type<char_type, _name, count>;         \
                                                                                   \
    static /* constexpr */ inline const name_member_map_t name_member_map =        \
          []<std::size_t... N>(std::index_sequence<N...> const&) {                 \
              return name_member_map_t{                                            \
                    {names.at(N), members.at(N)} \
                    ... \
              }; \
          }(index);                                                                \
                                                                                   \
    using member_name_map_t =                                                      \
          MODEL_NS::detail::member_name_map_type<char_type, _name, count>;         \
                                                                                   \
    static /* constexpr */ inline const member_name_map_t member_name_map =        \
          []<std::size_t... N>(std::index_sequence<N...> const&) {                 \
              return member_name_map_t{                                            \
                    {members.at(N), names.at(N)} \
                    ... \
              }; \
          }(index);


#define _SERIAL_ENUM_DEFINE(_name, _info, _memb)                                   \
    BOOST_PP_IF(BOOST_PP_ARRAY_SIZE(_memb), _SERIAL_ENUM_ENUM_DEFINE,              \
                _SERIAL_DISCARD)(_name, _info, _memb)                              \
                                                                                   \
          struct _SERIAL_NAME(_name)                                               \
        : MODEL_NS::SerialEnum<_SERIAL_NAME(_name), _name> {                       \
                                                                                   \
        static constexpr MODEL_NS::SerialMetadata<_name, _SERIAL_ENUM_MODEL_NAME(  \
                                                               _name, _info)>      \
              _metadata{_SERIAL_METADATA_ARGS(                                     \
                    _SERIAL_POP_TUPLE(_SERIAL_POP_TUPLE(_info)))};                 \
                                                                                   \
        BOOST_PP_IF(_SERIAL_ENUM_INLINE_P(_memb), _SERIAL_DISCARD,                 \
                    _SERIAL_ENUM_DEFS)(_name, _info, _memb)                        \
    }; /* SerialEnum subclass */                                                   \
    template <>                                                                    \
    struct MODEL_NS::detail::enum_model<_name>                                     \
        : std::type_identity<_SERIAL_NAME(_name)> {}

#define SERIAL_ENUM(_name, _info, ...)                                             \
    _SERIAL_ENUM_DEFINE(_name, _info, BOOST_PP_VARIADIC_TO_ARRAY(__VA_ARGS__))
