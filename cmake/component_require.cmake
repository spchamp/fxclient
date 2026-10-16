## component_require.cmake
#
# This source is in the public domain.  It is distributed in the hope that
# it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

include(FetchContent)

macro(component_require _name)
    ## this should generally be defined as a macro, when calling find_package

    set(_pkg_opts CONFIG GLOBAL)
    set(_options ${_pkg_opts})
    set(_single_value VERSION NOT_FOUND_MESSAGE)
    set(_multi_value COMPONENTS)
    cmake_parse_arguments(arg "${_options}" "${_single_value}" "${_multi_value}" ${ARGN})

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

    if(NOT DEFINED arg_NOT_FOUND_MESSAGE)
        set(arg_NOT_FOUND_MESSAGE "Using component ${_name} via FetchContent")
    endif()

    ## implicitly not required under find_package
    ##
    ## if not found under find_package(), then the sources will be built under FetchContent
    find_package(${_name} ${_pkg_args} QUIET)

    if(${_name}_FOUND)
        message(STATUS "Found component: ${_name}")
    else()
        message(STATUS ${arg_NOT_FOUND_MESSAGE})
        # message(STATUS "FetchContent_Declare(${_name} ${_ARGV} ...)")
        FetchContent_Declare(${_name} ${arg_UNPARSED_ARGUMENTS} SYSTEM OVERRIDE_FIND_PACKAGE)
        FetchContent_MakeAvailable(${_name})
    endif()

    foreach(_tmpvar IN LISTS _options _single_value _multi_value)
        unset(arg_${_tmpvar})
    endforeach()

endmacro()
