cmake_minimum_required(VERSION 4.2)
project( fault )

file( GLOB_RECURSE FAULT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" )

add_library( fault STATIC
    fault.h
    no_fault.h
    singleton_fault.h
    ${FAULT_SOURCES}
  )

add_library( wly::fault ALIAS fault )

target_include_directories( fault PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
  )

