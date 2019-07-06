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

set (VERSION 1.0.0)
add_definitions (-DCMAKE -DVERSION=\"${VERSION}\")

set_target_properties(utils PROPERTIES
	OUTPUT_NAME utils
	VERSION ${VERSION}
	SOVERSION 1
)

install(TARGETS utils DESTINATION /usr/local/lib)
install(FILES "lib/include/utils.h" DESTINATION /usr/local/include)
install(FILES "lib/include/defTypes.h" DESTINATION /usr/local/include)
