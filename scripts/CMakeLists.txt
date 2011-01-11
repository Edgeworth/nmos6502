cmake_minimum_required(VERSION 2.8)

set(PREFIX ../)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PREFIX})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PREFIX})

set(CMAKE_MODULE_PATH ./)
find_package(Boost REQUIRED)

file(GLOB_RECURSE SOURCE ${PREFIX}/src/*.cpp)
include_directories(${PREFIX}/include/ ${Boost_INCLUDE_DIRS})
add_definitions('-Wall' '-Wextra' '-ansi' '-O2')
#set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} '-pg')

add_executable(main ${SOURCE})
#target_link_libraries(main)
