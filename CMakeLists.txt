cmake_minimum_required (VERSION 3.17.0)

project (simpleProject LANGUAGES CXX C)

# Output the compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(src)
 