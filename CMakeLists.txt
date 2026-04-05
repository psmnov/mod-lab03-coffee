cmake_minimum_required (VERSION 3.10.2)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
add_compile_options(/MDd)
project (mod-lab03-coffee)
enable_testing()
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/")

add_subdirectory(src)
add_subdirectory(test)
