/// @brief common macros for serial type definitions

#pragma once

#ifndef BOOST_PP_LIMIT_TUPLE
#    define BOOST_PP_LIMIT_TUPLE 256
#endif

#ifndef BOOST_PP_LIMIT_VARIADIC
#    define BOOST_PP_LIMIT_VARIADIC 256
#endif
// #define BOOST_MPL_LIMIT_VECTOR_SIZE 50

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/array/elem.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/empty.hpp>
#include <boost/preprocessor/logical/and.hpp>
#include <boost/preprocessor/logical/or.hpp>
#include <boost/preprocessor/punctuation/paren.hpp>
#include <boost/preprocessor/list/to_tuple.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/tuple/size.hpp>
#include <boost/preprocessor/tuple/to_list.hpp>
#include <boost/preprocessor/repetition/enum.hpp>

#define _SERIAL_NAME(_name) BOOST_PP_CAT(SERIAL_PREFIX, _name)

#define _SERIAL_DISCARD(...)

#define _SERIAL_LITERAL(...) __VA_ARGS__

#define _SERIAL_POP_TUPLE(_tup)                                                    \
    BOOST_PP_LIST_TO_TUPLE(BOOST_PP_LIST_REST(BOOST_PP_TUPLE_TO_LIST(_tup)))


#define _ASERIAL_METADATA_ENUM(_z, _n, _md)                                        \
    ::fxsupport::metadata_param::BOOST_PP_TUPLE_ELEM(0,                              \
                                                   BOOST_PP_ARRAY_ELEM(_n, _md)) = \
          BOOST_PP_TUPLE_ELEM(1, BOOST_PP_ARRAY_ELEM(_n, _md))

#define _SERIAL_METADATA_ENUM(_z, _n, _md)                                         \
    ::fxsupport::metadata_param::BOOST_PP_TUPLE_ELEM(0,                              \
                                                   BOOST_PP_TUPLE_ELEM(_n, _md)) = \
          BOOST_PP_TUPLE_ELEM(1, BOOST_PP_TUPLE_ELEM(_n, _md))

/// "True" when _info represents a macro expression `()` or `(())` else "False"
#define _SERIAL_INFO_NONE(_info)                                                   \
    BOOST_PP_OR(                                                                   \
          BOOST_PP_CHECK_EMPTY(_info),                                             \
          BOOST_PP_OR(BOOST_PP_CHECK_EMPTY(BOOST_PP_TUPLE_ELEM(0, _info)),         \
                      BOOST_PP_AND(BOOST_PP_IS_BEGIN_PARENS(                       \
                                         BOOST_PP_TUPLE_ELEM(0, _info)),           \
                                   BOOST_PP_CHECK_EMPTY(BOOST_PP_TUPLE_ELEM(       \
                                         0, BOOST_PP_TUPLE_ELEM(0, _info))))))

/// if _info is of a format () or (()) then the stringized _name
/// else the first element from _info
#define _SERIAL_METADATA_NAME(_name, _info)                                        \
    BOOST_PP_IF(_SERIAL_INFO_NONE(_info),                                          \
                BOOST_PP_STRINGIZE(_name), BOOST_PP_TUPLE_ELEM(0, _info))

/// If _args is of a format () or (()) then no output,
/// else use a boost preprocessor enum macro, applying
///  _SERIAL_METADATA_ENUM  for each expression in _args.
///
/// The output of the expression will be wrapped in
/// punctuation "("  ... ")"
#define _SERIAL_METADATA_ARGS(_args)                                               \
    BOOST_PP_IF(_SERIAL_INFO_NONE(_args), BOOST_PP_EMPTY, BOOST_PP_LPAREN)()       \
          BOOST_PP_IF(_SERIAL_INFO_NONE(_args), _SERIAL_DISCARD, BOOST_PP_ENUM)(   \
                BOOST_PP_TUPLE_SIZE(_args), _SERIAL_METADATA_ENUM, _args)          \
                BOOST_PP_IF(_SERIAL_INFO_NONE(_args), BOOST_PP_EMPTY,              \
                            BOOST_PP_RPAREN)()
