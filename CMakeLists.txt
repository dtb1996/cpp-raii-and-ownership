cmake_minimum_required(VERSION 3.16)

project(cpp_raii_and_ownership
    VERSION 1.0
    LANGUAGES CXX
)

# Use modern C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define executable
add_executable(cpp_raii_and_ownership
    src/main.cpp
    src/scoped_timer.cpp
    src/scoped_file.cpp
)

# Public include directory
target_include_directories(cpp_raii_and_ownership
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Warnings (compiler-specific)
if (MSVC)
    target_compile_options(cpp_raii_and_ownership PRIVATE /W4 /WX)
else()
    target_compile_options(cpp_raii_and_ownership PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
