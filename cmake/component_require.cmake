## component_require.cmake
#
# This source is in the public domain.  It is distributed in the hope that
# it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

include(FetchContent)
include(GNUInstallDirs)

macro(component_require _name)
    ## this should generally be defined as a macro, when calling find_package

    set(_pkg_opts CONFIG)
    set(_options ${_pkg_opts})
    set(_single_value VERSION NOT_FOUND_MESSAGE 
        INCLUDE_PATH_VAR INCLUDE_PATH_NAME INCLUDE_SUBDIR
    )
    set(_multi_value COMPONENT)
    cmake_parse_arguments(arg "${_options}" "${_single_value}" "${_multi_value}" ${ARGN})

    set(_header_only_opts INCLUDE_PATH_VAR INCLUDE_SUBDIR INCLUDE_PATH_NAME)
    set(_package_only_opts VERSION COMPONENTS)

    set(_require_header OFF)

    foreach(_header_opt IN LISTS _header_only_opts)
        if(DEFINED arg_${_header_opt})
            set(_require_header ON)
            break()
        endif()
    endforeach()

    if(_require_header)
        foreach(_pkg_opt IN LISTS _package_only_opts)
            if(DEFINED arg_${_pkg_opt})
                message(FATAL_ERROR "Package requirement option ${_pkg_opt} is not supported for header requirements")
            endif()
        endforeach()
    else()
        foreach(_header_opt IN LISTS _header_only_opts)
            if(DEFINED arg_${_header_opt})
                message(FATAL_ERROR "Header requirement option ${_header_opt} is not supported for package requirements")
            endif()
        endforeach()
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

    if(NOT DEFINED arg_NOT_FOUND_MESSAGE)
        set(arg_NOT_FOUND_MESSAGE "Using package ${_name} via FetchContent")
    endif()

    if(_require_header)
        find_path(_header_dir NAMES ${arg_INCLUDE_PATH_NAME} OPTIONAL)
        if(${_header_dir} STREQUAL "_header_dir-NOTFOUND")
            set(${_name}_FOUND OFF)
        else()
            set(${_name}_FOUND ON)
        endif()
    else()
        find_package(${_name} ${_pkg_args} QUIET GLOBAL)
    endif()

    if(${_name}_FOUND)
        if(_require_header)
            message(STATUS "Found header: ${arg_INCLUDE_PATH_NAME} [${_header_dir}]")
        else()
            message(STATUS "Found package: ${_name}")
        endif()
        set(CACHE{${arg_INCLUDE_PATH_VAR}} TYPE FILEPATH FORCE
            VALUE ${_header_dir})
    else()
        message(STATUS ${arg_NOT_FOUND_MESSAGE})
        # message(STATUS "FetchContent_Declare(${_name} ${_ARGV} ...)")
        FetchContent_Declare(${_name} ${arg_UNPARSED_ARGUMENTS}
            SYSTEM OVERRIDE_FIND_PACKAGE)
        FetchContent_MakeAvailable(${_name})
        if(_require_header) 

            string(TOLOWER ${_name} _${_name}_lc)
            if(NOT DEFINED ${_${_name}_lc}_SOURCE_DIR)
                message(FATAL_ERROR "Lower-cased transform of ${_name} does not match source directory name")
            endif()

            unset(CACHE{${arg_INCLUDE_PATH_VAR}})
            unset(${arg_INCLUDE_PATH_VAR})

            if(DEFINED arg_INCLUDE_SUBDIR)
                set(${arg_INCLUDE_PATH_VAR} ${${_${_name}_lc}_SOURCE_DIR}/${arg_INCLUDE_SUBDIR})
            else()
                set(${arg_INCLUDE_PATH_VAR} ${${_${_name}_lc}_SOURCE_DIR})
            endif()
            set(CACHE{${arg_INCLUDE_PATH_VAR}} TYPE FILEPATH FORCE
                VALUE ${${arg_INCLUDE_PATH_VAR}})
        endif()
    endif()

    unset(CACHE{_header_dir})
endmacro()
