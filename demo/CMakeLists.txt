file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cc")
set(RESOURCES "helloDemo.exe.manifest")

# LPTSTR should be defined as wchar_t*
add_definitions(-DUNICODE)

# Make sure the compiler can find include files from our Hello library.
include_directories(${basiccmake_SOURCE_DIR}/hello)

# Make sure the linker can find the Hello library once it is built.
link_directories(${basiccmake_BINARY_DIR}/hello)

# Add executable called "helloDemo" that is built from the source files
# "demo.cc" and "demo_b.cc". The extensions are automatically found.
add_executable(helloDemo WIN32 ${SRCS} ${INCS} ${RESOURCES})

# Create filters within Visual Studio for resources
source_group("Resource Files" FILES ${RESOURCES})

# Link the executable to the Hello library.
# Boost_LIBRARIES was setup up in the root cmake file and includes the
# filesystem and system libraries.
target_link_libraries(helloDemo libHello ${Boost_LIBRARIES})

# Run the mt tool as a post build to embed helloDemo.exe.manifest
get_property(helloDemo_exe_location TARGET helloDemo PROPERTY LOCATION)
add_custom_command(
  TARGET helloDemo
  POST_BUILD
  COMMAND "mt.exe" -manifest \"${CMAKE_CURRENT_SOURCE_DIR}\\helloDemo.exe.manifest\" -outputresource:\"${helloDemo_exe_location}\"\;\#1 /nologo
  COMMENT "Adding manifest"
)
