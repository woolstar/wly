cmake_minimum_required(VERSION 4.0)

include(CMakePackageConfigHelpers)

file( GLOB_RECURSE BUFFER_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )
add_library( buffer ${BUFFER_SOURCES} )
add_library(wly::buffer ALIAS buffer)

target_compile_features( buffer PUBLIC cxx_std_23 )

target_include_directories(buffer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
  )

file( GLOB_RECURSE BUFFER_TESTS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/test/*.cpp" )
add_executable( gtest-buffer-unit ${BUFFER_TESTS} )
target_link_libraries( gtest-buffer-unit PUBLIC gtest gtest_main gmock buffer )

add_test( NAME gtest-unit COMMAND $<TARGET_FILE:gtest-buffer-unit> )

