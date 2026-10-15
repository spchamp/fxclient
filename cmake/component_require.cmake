## component_require.cmake
#
# This source is in the public domain.  It is distributed in the hope that
# it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

include(FetchContent)

macro(component_require _name)
    ## this generally must be defined as a macro, when calling find_package

    set(_pkg_opts CONFIG QUIET GLOBAL) ## not REQUIRED
    set(_fetch_single_args GIT_REPOSITORY GIT_TAG)
    set(_options ${_pkg_opts})
    set(_single_value VERSION NOT_FOUND_MESSAGE ${_fetch_single_args})
    set(_multi_value COMPONENTS CMAKE_ARGS)
    cmake_parse_arguments(arg "${_options}" "${_single_value}" "${_multi_value}" ${ARGN})

    if(arg_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "component_require: Unrecognized options: ${arg_UNPARSED_ARGUMENTS}")
    endif()

    set(_pkg_args)
    if(DEFINED arg_VERSION)
        list(APPEND _pkg_args ${arg_VERSION})
    endif()
    foreach(_argopt ${_pkg_opts})
        if(arg_${_argopt})
            list(APPEND _pkg_args ${_argopt})
        endif()
    endforeach()
    if(DEFINED arg_COMPONENTS)
        list(APPEND _pkg_args COMPONENT ${arg_COMPONENTS})
    endif()

    set(_cmd_declare_args)
    if(DEFINED arg_CMAKE_ARGS)
        # FIXME unfortunately useless with the archaic cmake minimum version in oatpp
        list(APPEND _cmd_declare_args CMAKE_ARGS ${arg_CMAKE_ARGS})
    endif()
    foreach(_sv ${_fetch_single_args})
        if(DEFINED arg_${_sv})
            list(APPEND _cmd_declare_args ${_sv} ${arg_${_sv}})
        endif()
    endforeach()

    if(NOT DEFINED arg_NOT_FOUND_MESSAGE)
        set(arg_NOT_FOUND_MESSAGE "Using component ${_name} via FetchContent")
    endif()

    find_package(${_name} ${_pkg_args} QUIET)

    if(${_name}_FOUND)
        message(STATUS "Found component: ${_name}")
    else()
        message(STATUS ${arg_NOT_FOUND_MESSAGE})
        message(STATUS "FetchContent_Declare(${_name} ${_cmd_declare_args} ...)")
        FetchContent_Declare(${_name} ${_cmd_declare_args} SYSTEM OVERRIDE_FIND_PACKAGE)
        FetchContent_MakeAvailable(${_name})
    endif()

    foreach(_tmpvar IN LISTS _options _single_value _multi_value)
        unset(arg_${_tmpvar})
    endforeach()

endmacro()
