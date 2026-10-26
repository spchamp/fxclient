## deftarget.cmake
#
# This source is in the public domain.  It is distributed in the hope that
# it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

macro(_tgt_scoped _tgt _prefix _scope _optname _suffix)
    if(DEFINED ${_prefix}_${_scope}_${_optname})
        cmake_language(CALL target_${_suffix} ${_tgt} ${_scope} ${${_prefix}_${_scope}_${_optname}})
    endif()
endmacro()


function(deftarget _name)
    set(_any_tgt_opts EXCLUDE_FROM_ALL IMPORTED)
    set(_add_library_opts SYMBOLIC)
    set(_add_executable_opts WIN32 MACOSX_BUNDLE ALIAS)

    set(_options ${_any_tgt_opts} ${_add_library_opts} ${_add_executable_opts})
    set(_single_value TYPE LINKER_LANGUAGE)
    set(_multi_value SOURCES PRIVATE_SOURCES HEADERS HEADER_DIRS PRIVATE_HEADERS)
    foreach(_ctx LIBRARIES LINK_DIRS INCLUDES DEFINES OPTIONS FEATURES PRECOMPILE)
        foreach(_scope PUBLIC PRIVATE INTERFACE)
            list(APPEND _multi_value ${_scope}_${_ctx})
        endforeach()
    endforeach()
    cmake_parse_arguments(PARSE_ARGV 1 arg "${_options}" "${_single_value}" "${_multi_value}")

    #
    # checks & post-processing for args
    #

    if(arg_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "deftarget: Unrecognized options: ${arg_UNPARSED_ARGUMENTS}")
    endif()

    set(_lib_tgt_types STATIC SHARED MODULE OBJECT INTERFACE UNKNOWN)
    set(_exec_tgt_types EXEC)

    set(_tgt_opts)

    set(_add_executable_unsup ${_add_library_opts})
    set(_add_library_unsup ${_add_executable_opts})


    #
    # define _tgt_cmd and arg_type
    #

    if(NOT DEFINED arg_SOURCES)
        set(_tgt_cmd add_library)
        if(NOT DEFINED arg_TYPE)
            set(arg_TYPE INTERFACE)
            ## FIXME building with clang-cl is a freaking mess
            # set(arg_SYMBOLIC ON) # problematic w/ vcpkg tooling
        endif()
    endif()

    if(NOT DEFINED arg_TYPE)
        if(BUILD_SHARED_LIBS)
            message(STATUS "deftarget ${_name}: using library target type SHARED")
            set(arg_TYPE SHARED)
        else()
            message(STATUS "deftarget ${_name}: using library target type STATIC")
            set(arg_TYPE STATIC)
        endif()
    endif()

    if(NOT DEFINED _tgt_cmd)
        foreach(_typ ${_lib_tgt_types})
            if(${arg_TYPE} STREQUAL ${_typ})
                set(_tgt_cmd add_library)
            endif()
        endforeach()
    endif()

    if(NOT DEFINED _tgt_cmd)
        foreach(_typ ${_exec_tgt_types})
            if(${arg_TYPE} STREQUAL ${_typ})
                set(_tgt_cmd add_executable)
            endif()
        endforeach()
    endif()

    if(NOT DEFINED _tgt_cmd)
        message(FATAL_ERROR "deftarget: Unrecognized tgt TYPE ${arg_TYPE}")
    endif()

    if(NOT DEFINED arg_HEADER_DIRS)
        set(arg_HEADER_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
    endif()

    #
    # Parse any option flags for _tgt_cmd
    #
    foreach(_opt ${_any_tgt_opts})
        if(arg_${opt})
            list(APPEND _tgt_opts ${_opt})
        endif()
    endforeach()

    ## Check for invalid options; Add valid options to _tgt_opts
    foreach(_cmd_str add_library add_executable)
        foreach(_opt ${_${_cmd_str}_unsup})
            if(arg_${_opt} AND NOT arg_TYPE STREQUAL "INTERFACE")
                # ^ FIXME the second part is a hack on a hack here,
                # in trying to work this function out for add_library(name INTERFACE SYMBOLIC)
                message(FATAL_ERROR "deftarget: Option ${_opt} is not supported for TYPE ${arg_TYPE}")
            endif()
        endforeach()

        foreach(_opt ${_${_cmd_str}_opts})
            if(arg_${_opt})
                list(APPEND _tgt_opts ${_opt})
            endif()
        endforeach()
    endforeach()

    if(arg_SYMBOLIC AND NOT (${arg_TYPE} STREQUAL INTERFACE))
        message(FATAL_ERROR "deftarget: Option SYMBOLIC is only supported for TYPE INTERFACE")
    endif()

    if(NOT DEFINED arg_SOURCES)
        set(arg_SOURCES)
    endif()

    if(DEFINED arg_HEADERS)
        if(opt_INTERFACE)
            set(_headers_visibility INTERFACE)
        else()
            set(_headers_visibility PUBLIC)
        endif()
    endif()


    ## initial target decl

    if(arg_SYMBOLIC)
        list(APPEND _tgt_opts SYMBOLIC)
    endif()

    cmake_language(CALL ${_tgt_cmd} ${_name} ${_tgt_opts} ${arg_SOURCES} )

    if(DEFINED arg_LINKER_LANGUAGE)
        set_target_properties(${_name} PROPERTIES LINKER_LANGUAGE ${arg_LINKER_LANGUAGE})
    else()
        get_target_property(arg_LINKER_LANGUAGE ${_name} LINKER_LANGUAGE)
    endif()

    ## scoped funtion calls (target_%)
    ## i.e LIBRARIES LINK_DIRS INCLUDES DEFINES OPTIONS FEATURES PRECOMPILE
    foreach(_scope PUBLIC PRIVATE INTERFACE)
        _tgt_scoped(${_name} arg ${_scope} LIBRARIES link_libraries)
        _tgt_scoped(${_name} arg ${_scope} LINK_DIRS link_directories)
        _tgt_scoped(${_name} arg ${_scope} INCLUDES include_directories) # FIXME build interface ...
        _tgt_scoped(${_name} arg ${_scope} DEFINES compile_definitions)
        _tgt_scoped(${_name} arg ${_scope} OPTIONS compile_options)
        _tgt_scoped(${_name} arg ${_scope} FEATURES compile_features)
        _tgt_scoped(${_name} arg ${_scope} PRECOMPILE precompile_headers)
    endforeach()

    if(DEFINED arg_PRIVATE_SOURCES)
        target_sources(${_name} PRIVATE ${arg_PRIVATE_SOURCES})
    endif()

    if(DEFINED arg_HEADERS)
        target_sources(${_name} ${_headers_visibility}
            FILE_SET headers TYPE HEADERS
            BASE_DIRS ${arg_HEADER_DIRS}
            FILES ${arg_HEADERS}
        )
    endif()

    if(DEFINED arg_PRIVATE_HEADERS)
        target_sources(${_name} PRIVATE FILE_SET private_headers TYPE HEADERS FILES ${arg_HEADERS})
    endif()

    if(FX_CCACHE)
        set_property(TARGET ${_name} PROPERTY ${arg_LINKER_LANGUAGE}_COMPILER_LAUNCHER ${CCACHE_BIN})
    endif()

endfunction()
