## fxclient CMake build

## CMake version for SPDX_LICENSE in project()
cmake_minimum_required(VERSION 4.3)

project(fxclient
    LANGUAGES CXX
    SPDX_LICENSE BSD-2-Clause
)

set(CMAKE_CXX_STANDARD 23)

if(POLICY CMP0210)
    ## apply CMAKE_<LANG>_LINK_FLAGS to all tgts
    cmake_policy(SET CMP0210 NEW)
endif()

find_program(CCACHE_BIN ccache)
if(NOT CCACHE_BIN MATCHES "NOTFOUND")
    set(HAVE_CCACHE ON)
endif()

option(FX_KWALLET "Build with kf5wallet for API token access" ON)

option(FX_CCACHE "Use ccache for build" ${HAVE_CCACHE})

if(WIN32)
    set(CACHE{BUILD_SHARED_LIBS} VALUE OFF)
endif()

option(FX_OAT "Build components for oatpp" OFF)

option(FX_BUILD_SHARED_LIBS "Build libraries as shared objects" ${BUILD_SHARED_LIBS})
option(FX_BUILD_TESTING "Build tests" ${PROJECT_IS_TOP_LEVEL})

set(CACHE{BUILD_SHARED_LIBS} FORCE VALUE ${FX_BUILD_SHARED_LIBS})


if(FX_CCACHE)
    if(CCACHE_BIN AND NOT HAVE_CCACHE)
        message(FATAL_ERROR "FX_CCACHE option was defined but ccache was not found")
    endif()
endif()

include(GNUInstallDirs)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/component_require.cmake)

if(DEFINED ENV{VCPKG_ROOT})
    set(CACHE{FX_VCPKG_BUILD} TYPE INTERNAL VALUE ON)
else()
    set(CACHE{FX_VCPKG_BUILD} TYPE INTERNAL VALUE OFF)
endif()

set(FX_BOOST_COMPONENTS)
set(FX_BOOST_LIBS)
set(FX_DEFINES)

set(FX_INCLUDES
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

if(FX_VCPKG_BUILD)
    list(APPEND FX_BOOST_COMPONENTS
        asio decimal mpl parameter
        preprocessor system type_index
    )
    foreach(_L ${FX_BOOST_COMPONENTS})
        list(APPEND FX_BOOST_LIBS Boost::${_L})
    endforeach()
else()
    list(APPEND FX_BOOST_LIBS Boost::boost)
    component_require(boost_decimal
        GIT_REPOSITORY https://github.com/boostorg/decimal.git
        GIT_TAG boost-1.92.0
    )
    list(APPEND FX_LIBS boost_decimal::boost_decimal)
endif()

find_package(Boost REQUIRED COMPONENTS ${FX_BOOST_COMPONENTS})

# build options for conjure_enum
set(CACHE{BUILD_UNITTESTS} VALUE OFF)
#
find_path(CONJURE_ENUM_CHECK NAMES "fix8/conjure_enum.hpp" OPTIONAL)
if(CONJURE_ENUM_CHECK STREQUAL CONJURE_ENUM_CHECK-NOTFOUND)
    if(DEFINED BUILD_TESTING)
        set(_build_testing_orig ${BUILD_TESTING})
    else()
        set(_build_testing_orig OFF)
    endif()
    # FIXME the conjure_enum tests are still being built
    set(CACHE{BUILD_TESTING} FORCE VALUE OFF)
    component_require(conjure_enum
        INCLUDE_PATH_VAR CONJURE_ENUM_INCLUDE_DIR
        INCLUDE_PATH_NAME "fix8/conjure_enum.hpp"
        INCLUDE_SUBDIR include
        GIT_REPOSITORY https://github.com/fix8mt/conjure_enum.git
        GIT_TAG v1.2.0
        GIT_SHALLOW ON
    )
    set(CACHE{BUILD_TESTING} FORCE VALUE ${_build_testing_orig})
endif()
list(APPEND FX_INCLUDES
    ${CONJURE_ENUM_INCLUDE_DIR}
)


foreach(_opt in tests benchmark coverage installation)
    set(CACHE{frozen.${_opt}}
        HELP "Frozen build option, when sourced with FetchContent"
        TYPE INTERNAL VALUE OFF
    )
endforeach()
component_require(frozen
    GIT_REPOSITORY https://github.com/serge-sans-paille/frozen.git
    GIT_TAG 6791f856c7ff69010004e0a456af8ac43935ed80
    GIT_SHALLOW ON
)


component_require(reflectcpp
    GIT_REPOSITORY https://github.com/munich-data-engineering/reflect-cpp.git
    GIT_TAG v0.27.1
    GIT_SHALLOW ON
)
list(APPEND FX_LIBS reflectcpp::reflectcpp)


if(FX_OAT)
    if(FX_VCPKG_BUILD)
        find_package(oatpp CONFIG REQUIRED)
        set(CACHE{OAT_LIBS} TYPE INTERNAL VALUE oatpp::oatpp
        )
    else()
        set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
        component_require(oatpp
            GIT_REPOSITORY https://github.com/oatpp/oatpp.git
            GIT_TAG 1.3.1
            GIT_SHALLOW ON
        )
        find_package(oatpp REQUIRED)
        set(CACHE{OAT_LIBS} TYPE INTERNAL VALUE oatpp::oatpp)
    endif()
endif()



set(FX_LIBS ${FX_BOOST_LIBS} frozen::frozen reflectcpp::reflectcpp)


include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/deftarget.cmake)
add_subdirectory(src)

if(FX_OAT)
    add_executable(fxmain_stub Fxmain-api-client.cpp)
    target_link_libraries(fxmain_stub PRIVATE ${OAT_LIBS})
    target_include_directories(fxmain_stub PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/api ${CMAKE_CURRENT_SOURCE_DIR}/model)

    if(FX_CCACHE)
        set_property(TARGET fxmain_stub PROPERTY CXX_COMPILER_LAUNCHER ${CCACHE_BIN})
    endif()
endif()

if(FX_BUILD_TESTING)
    component_require(Catch2 VERSION 3 CONFIG
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.15.2
        GIT_SHALLOW ON
        NOT_FOUND_MESSAGE "BUILD_TESTING is defined but Catch2 version 3 was not found. Adding dependency with FetchContent"
    )
    include(Catch)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/add_catch_test.cmake)
    add_subdirectory(test)
endif()

## record variables for review in cmake cache
foreach(_vv FX_INCLUDES FX_LIBS FX_DEFINES)
    SET(CACHE{${_vv}} TYPE INTERNAL VALUE ${${_vv}})
endforeach()
