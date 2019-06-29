cmake_minimum_required(VERSION 2.8)

project (utils)

SET(CMAKE_SYSTEM_NAME Linux)  

if(APPLE)
  include_directories( /usr/local/include )
  link_directories( /usr/local/lib/ )
endif()

include_directories( lib/include/ )
file(GLOB headers "lib/include/*.h" )
file(GLOB sources "lib/src/*.c" )

add_library(utils SHARED ${sources} ${headers})