cmake_minimum_required(VERSION 3.10)
project(HuffmanEncoding)

set(CMAKE_CXX_STANDARD 17)

# Add executable and source files
add_executable(HuffmanEncoding
    main.cpp
    encode.cpp
    fileinout.cpp
)