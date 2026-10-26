## add_catch_test.cmake
#
# This source is in the public domain.  It is distributed in the hope that
# it will be useful, but WITHOUT ANY WARRANTY; without even the implied
# warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#

if(NOT TARGET ${CMAKE_PROJECT_NAME}_test_libs)
    add_library(${CMAKE_PROJECT_NAME}_test_libs INTERFACE)
endif()

function(add_catch_test test_name)
    set(_options CUSTOM_MAIN)
    set(_single_value)
    set(_multi_value SOURCES LIBRARIES INCLUDE SYSTEM_INCLUDE DEFINE)
    cmake_parse_arguments(PARSE_ARGV 1 arg "${_options}" "${_single_value}" "${_multi_value}")

    if(arg_UNPARSED_ARGUMENTS)
        message(FATAL_ERROR "add_catch_test: Unrecognized options: ${arg_UNPARSED_ARGUMENTS}")
    endif()

    if(NOT DEFINED arg_SOURCES)
        set(arg_SOURCES ${test_name}.cpp)
    endif()

    if(EXISTS ${CMAKE_CURRENT_LIST_DIR}/_include)
        message(STATUS "test ${test_name} automatic includes: ${CMAKE_CURRENT_LIST_DIR}/_include")
        if(NOT DEFINED arg_INCLUDE)
            set(arg_INCLUDE)
        endif()
        list(PREPEND arg_INCLUDE ${CMAKE_CURRENT_LIST_DIR}/_include)
    endif()

    if(arg_CUSTOM_MAIN)
        list(APPEND arg_LIBRARIES Catch2::Catch2)
    else()
        list(APPEND arg_LIBRARIES Catch2::Catch2WithMain)
    endif()

    list(REMOVE_DUPLICATES arg_SOURCES)
    if(DEFINED arg_LIBRARIES)
        list(REMOVE_DUPLICATES arg_LIBRARIES)
    endif()
    list(REMOVE_DUPLICATES arg_INCLUDE)
    list(REMOVE_DUPLICATES arg_SYSTEM_INCLUDE)

    add_executable(${test_name} ${arg_SOURCES})

    if(EXISTS ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/include)
        target_include_directories(${test_name} PRIVATE ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/include)
    elseif(EXISTS ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src)
        target_include_directories(${test_name} PRIVATE ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src)
    endif()

    if(EXISTS ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/include/test)
        target_include_directories(${test_name} PRIVATE ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/include/test)
    elseif(EXISTS ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src/test)
        target_include_directories(${test_name} PRIVATE ${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src/test)
    endif()


    if(DEFINED arg_INCLUDE)
        message(STATUS "test ${test_name} includes: ${arg_INCLUDE}")
        target_include_directories(${test_name} PRIVATE ${arg_INCLUDE})
    endif()

    if(DEFINED arg_SYSTEM_INCLUDE)
        target_include_directories(${test_name} SYSTEM PRIVATE ${arg_SYSTEM_INCLUDE})
    endif()

    if(DEFINED arg_DEFINE)
        target_compile_definitions(${test_name} PRIVATE ${arg_DEFINE})
    endif()


    if(DEFINED arg_LIBRARIES)
        ## DEBUG (linking w/ cmake for static builds on windows platforms)
        # message("add_catch_test: Link test ${test_name} with libraries ${arg_LIBRARIES}")
        target_link_libraries(${test_name} PRIVATE ${arg_LIBRARIES})

        foreach(_ll IN LISTS arg_LIBRARIES)
            if(_ll MATCHES "::")
                get_target_property(_ll_incdirs ${_ll} INCLUDE_DIRECTORIES)
                if(NOT _ll_incdirs MATCHES "NOTFOUND")
                    message("add_catch_test: Build test ${test_name} with include dirs ${_ll_incdirs} for library ${_ll}")
                    target_include_directories(${test_name} PRIVATE ${_ll_incdirs})
                endif()
            endif()
        endforeach()
    endif()


    get_target_property(arg_LINKER_LANGUAGE ${test_name} LINKER_LANGUAGE)
    if(FX_CCACHE)
        set_property(TARGET ${test_name} PROPERTY ${arg_LINKER_LANGUAGE}_COMPILER_LAUNCHER ${CCACHE_BIN})
    endif()

    catch_discover_tests(${test_name})
endfunction()
