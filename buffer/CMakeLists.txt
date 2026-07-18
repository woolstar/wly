cmake_minimum_required(VERSION 4.0)

project(buffer LANGUAGES CXX)
include(CMakePackageConfigHelpers)

file( GLOB_RECURSE BUFFER_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )

add_library(buffer
    ${BUFFER_SOURCES}
  )

add_library(wly::buffer ALIAS buffer)

target_compile_features(buffer PUBLIC
    cxx_std_23
  )

target_include_directories(buffer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
  )

