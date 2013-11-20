file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cc")

# LPTSTR should be defined as wchar_t*
add_definitions(-DUNICODE)

# Make sure the compiler can find include files from our Hello library.
include_directories(${basiccmake_SOURCE_DIR}/hello)

# Make sure the linker can find the Hello library once it is built.
link_directories(${basiccmake_BINARY_DIR}/hello)

# Add executable called "helloDemo" that is built from the source files
# "demo.cc" and "demo_b.cc". The extensions are automatically found.
add_executable(helloDemo WIN32 ${SRCS} ${INCS})

# Link the executable to the Hello library.
target_link_libraries(helloDemo libHello ${Boost_LIBRARIES})