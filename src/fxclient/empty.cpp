// Empty source file
//
// This is a hack due to some platform limitations for interface libraries
// in Cmake, when building with msvc or clang-cl.
//
// For some library L that would otherwise be defined as an interface library
// in CMake, typically no L.lib file would be produced when compiling with msvc
// or clang-cl. Subsequently, if L is defined instead as a static/shared library,
// containing only empty.cpp as a source file, then L.lib will be produced, such
// that another CMake source object may successfully link to L under CMake
