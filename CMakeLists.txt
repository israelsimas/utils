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

IF(TESTS)

  file(GLOB headers ${headers} "tests/include/*.h" )
  file(GLOB sources ${sources} "tests/src/*.cpp" )

  add_library(utils SHARED ${sources} ${headers})

  target_link_libraries( utils CppUTest CppUTestExt )
  add_executable( RunAllTests ${sources} ${headers} )
  target_link_libraries(RunAllTests utils CppUTest CppUTestExt )

ELSE()
  add_library(utils SHARED ${sources} ${headers})
ENDIF(TESTS)
