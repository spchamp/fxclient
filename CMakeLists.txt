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
set(CACHE{BUILD_TESTING} FORCE VALUE ${FX_BUILD_TESTING})

if(FX_CCACHE)
    if(CCACHE_BIN AND NOT HAVE_CCACHE)
        message(FATAL_ERROR "FX_CCACHE option was defined but ccache was not found")
    endif()
endif()

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/component_require.cmake)

if(DEFINED ENV{VCPKG_ROOT})
    set(CACHE{FX_VCPKG_BUILD} TYPE INTERNAL VALUE ON)
else()
    set(CACHE{FX_VCPKG_BUILD} TYPE INTERNAL VALUE OFF)
endif()

set(FX_BOOST_COMPONENTS)
set(FX_BOOST_LIBS)

if(FX_VCPKG_BUILD)
    ## Boost::logic a.k.a tribool
    list(APPEND FX_BOOST_COMPONENTS asio exception logic mpl outcome parameter system type_index)
    foreach(_L ${FX_BOOST_COMPONENTS})
        list(APPEND FX_BOOST_LIBS Boost::${_L})
    endforeach()
else()
    list(APPEND FX_BOOST_LIBS Boost::boost)
endif()

find_package(Boost COMPONENTS ${FX_BOOST_COMPONENTS})



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
        )
        find_package(oatpp REQUIRED)
        set(CACHE{OAT_LIBS} TYPE INTERNAL VALUE oatpp::oatpp)
    endif()
endif()

include(GNUInstallDirs)


component_require(reflectcpp
    GIT_REPOSITORY https://github.com/munich-data-engineering/reflect-cpp.git
    GIT_TAG v0.26.2)

component_require(frozen
    GIT_REPOSITORY https://github.com/serge-sans-paille/frozen.git
    GIT_TAG d53e0a11578d56dc331dc267c2084d52bcdee1d9)

set(FXCLIENT_LIBS ${FX_BOOST_LIBS} frozen::frozen reflectcpp::reflectcpp)

set(FXCLIENT_INCLUDES
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

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
        NOT_FOUND_MESSAGE "BUILD_TESTING is defined but Catch2 version 3 was not found. Adding dependency with FetchContent"
    )
    include(Catch)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/add_catch_test.cmake)
    add_subdirectory(test)
endif()

