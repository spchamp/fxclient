#pragma once

// include this first
#include <fxsupport/serial_macros.hpp>

#include <cstdint>   // IWYU pragma: keep
#include <optional>  // IWYU pragma: keep
#include <string>    // IWYU pragma: keep
#include <vector>    // IWYU pragma: keep

#include <fxsupport/Fields.hpp>
#include <fxsupport/SerialMetadata.hpp>
#include <fxsupport/SerialObject.hpp>

#include <boost/preprocessor/array/to_list.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/comparison/greater.hpp>
#include <boost/preprocessor/control/expr_if.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/facilities/va_opt.hpp>
#include <boost/preprocessor/list/adt.hpp>
#include <boost/preprocessor/list/for_each.hpp>
#include <boost/preprocessor/punctuation/comma.hpp>
#include <boost/preprocessor/punctuation/paren.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/remove.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/variadic/to_array.hpp>

#define _SERIAL_FIELD_PARAM_ENUM(_z, _n, _params) BOOST_PP_TUPLE_ELEM(_n, _params)

#define _SERIAL_FIELD_NAME_IMPL(_field)                                            \
    BOOST_PP_IF(BOOST_PP_GREATER(BOOST_PP_TUPLE_SIZE(_field), 2),                  \
                BOOST_PP_TUPLE_ELEM(2, _field),                                    \
                BOOST_PP_STRINGIZE( \
                        BOOST_PP_TUPLE_ELEM( \
                            0, _field)))


#define _SERIAL_FIELD_REST_IMPL(_field)                                            \
    BOOST_PP_IF(BOOST_PP_GREATER(BOOST_PP_TUPLE_SIZE(_field), 3), BOOST_PP_ENUM,   \
                _SERIAL_DISCARD)(                                                  \
          BOOST_PP_SUB(BOOST_PP_TUPLE_SIZE(_field), 3), _SERIAL_FIELD_PARAM_ENUM,  \
          BOOST_PP_TUPLE_REMOVE(                                                   \
                BOOST_PP_TUPLE_REMOVE(BOOST_PP_TUPLE_REMOVE(_field, 0), 0), 0))

#define _SERIAL_FIELD_T(_cls, _field)                                              \
    MODEL_NS::NamedField<BOOST_PP_TUPLE_ELEM(1, _field),                           \
                         _SERIAL_FIELD_NAME_IMPL(_field),                          \
                         _cls BOOST_PP_IF(                                         \
                               BOOST_PP_GREATER(BOOST_PP_TUPLE_SIZE(_field), 3),   \
                               BOOST_PP_COMMA, BOOST_PP_EMPTY)()                   \
                               _SERIAL_FIELD_REST_IMPL(_field)>


#define _SERIAL_FIELD_T_ENUM(_z, _n, _defs)                                        \
    _SERIAL_FIELD_T(BOOST_PP_LIST_FIRST(_defs),                                    \
                    BOOST_PP_ARRAY_ELEM(_n, BOOST_PP_LIST_REST(_defs)))

/// define a non-static data member for the field
///
/// this macro will be applied when defining a SerialObject subclass
#define _SERIAL_MEMB_EACH(_r, _cls, _def)                                          \
    std::optional<BOOST_PP_TUPLE_ELEM(1, _def)> BOOST_PP_TUPLE_ELEM(0, _def){      \
          std::nullopt};

// provide a static reference for std::mem_fn from the class-scoped data member
// for the field under _defs
#define _SERIAL_MEMB_REF_ENUM(_z, _n, _defs)                                       \
    &BOOST_PP_LIST_FIRST(_defs)::BOOST_PP_TUPLE_ELEM(                              \
          0, BOOST_PP_ARRAY_ELEM(_n, BOOST_PP_LIST_REST(_defs)))

#define _SERIAL_CLS_COMMA_IF(_fields)                                              \
    BOOST_PP_IF(BOOST_PP_ARRAY_SIZE(_fields), BOOST_PP_COMMA, BOOST_PP_EMPTY)()

#define _SERIAL_CLASS_DEFINE(_name, _info, _afields)                               \
    struct _name                                                                   \
        : MODEL_NS::SerialObject<_name _SERIAL_CLS_COMMA_IF(                       \
                _afields) BOOST_PP_ENUM(BOOST_PP_ARRAY_SIZE(_afields),             \
                                        _SERIAL_FIELD_T_ENUM,                      \
                                        BOOST_PP_LIST_CONS(_name, _afields))> {    \
                                                                                   \
        using _base_type = MODEL_NS::SerialObject<_name _SERIAL_CLS_COMMA_IF(      \
              _afields) BOOST_PP_ENUM(BOOST_PP_ARRAY_SIZE(_afields),               \
                                      _SERIAL_FIELD_T_ENUM,                        \
                                      BOOST_PP_LIST_CONS(_name, _afields))>;       \
                                                                                   \
        static constexpr const MODEL_NS::                                          \
              SerialMetadata<_name, _SERIAL_METADATA_NAME(_name, _info)>           \
                    _metadata{_SERIAL_METADATA_ARGS(                               \
                          _SERIAL_POP_TUPLE(_SERIAL_POP_TUPLE(_info)))};           \
                                                                                   \
        BOOST_PP_EXPR_IF(BOOST_PP_ARRAY_SIZE(_afields),                            \
                         BOOST_PP_LIST_FOR_EACH(_SERIAL_MEMB_EACH, _name,          \
                                                BOOST_PP_ARRAY_TO_LIST(_afields))) \
                                                                                   \
        static constexpr _base_type::_fields_type _fields{                         \
              BOOST_PP_ENUM(BOOST_PP_ARRAY_SIZE(_afields), _SERIAL_MEMB_REF_ENUM,  \
                            BOOST_PP_LIST_CONS(_name, _afields))};                 \
    };


/// @brief define a SerialObject model class, ...
#define SERIAL_CLASS(_name, _info, ...)                                            \
    _SERIAL_CLASS_DEFINE(_name, _info, BOOST_PP_VARIADIC_TO_ARRAY(__VA_ARGS__))
