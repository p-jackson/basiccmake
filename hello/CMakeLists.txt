file(GLOB_RECURSE INCS "*.h")
file(GLOB_RECURSE SRCS "*.cc")

# Create a library called "Hello" which includes the source file "hello.cc".
# The extension is already found. Any number of sources could be listed here.
add_library(libHello ${SRCS} ${INCS})
