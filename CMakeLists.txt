## fxclient CMake build

## CMake version for CACHE{VAR} syntax
cmake_minimum_required(VERSION 4.2)

project(fxclient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/component_require.cmake)

## set minimum CMake version for OAT++ 1.3.1
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
component_require(OATPP
    GIT_REPOSITORY https://github.com/oatpp/oatpp.git
    GIT_TAG 1.3.1
)

include_directories(model)
include_directories(api)
include_directories(impl)

file(GLOB SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
find_package(oatpp REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE oatpp)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} ws2_32)
endif(WIN32)
