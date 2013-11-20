# The name of our project is "basiccmake". CMakeLists files in this project can
# refer to the root source directory of the project as ${basiccmake_SOURCE_DIR} and
# to the root binary directory of the project as ${basiccmake_BINARY_DIR}.
cmake_minimum_required(VERSION 2.8)
project(basiccmake)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.54 COMPONENTS filesystem system REQUIRED)

add_definitions(-DBOOST_ALL_NO_LIB)
include_directories(${Boost_INCLUDE_DIR})

# Recurse into the "Hello" and "Demo" subdirectories. This does not actually 
# cause another cmake executable to run. The same process will walk through 
# the project's entire directory structure. 
add_subdirectory(hello)
add_subdirectory(demo)
