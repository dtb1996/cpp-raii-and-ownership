# cpp-raii-and-ownership

A focused C++ project demonstrating RAII, ownership semantics, and move-only resource management using modern C++ (C++20).

This repository is intentionally engine-agnostic and avoids frameworks to highlight core language understanding.

## Goals

- Demonstrate correct resource lifetime management
- Apply RAII principles consistently
- Implement move-only types
- Show understanding of the Rule of Five
- Avoid memory leaks and undefined behavior
- Be portable across platforms and compilers

## Project Structure

```bash
cpp-raii-and-ownership/
├── include/
│   ├── scoped_timer.h
│   └── scoped_file.h
├── src/
│   ├── main.cpp
│   ├── scoped_timer.cpp
│   └── scoped_file.cpp
├── CMakeLists.txt
├── .gitattributes
├── .gitignore
└── README.md
```

## Implemented Components

### ScopedTimer

A simple RAII utility that measures elapsed time for a scope.

#### Features

- Starts timing on construction
- Reports elapsed time on destruction
- Move-only (non-copyable)
- Zero global state

#### Concepts

- Deterministic destruction
- Move semantics
- Stack-based lifetime management

### ScopedFile

An RAII wrapper around FILE\*.

#### Features

- Opens file in constructor
- Closes file in destructor
- Non-copyable, movable
- Explicit ownership semantics

#### Concepts

- Resource ownership
- Rule of Five
- Exception safety

## Key Concepts Demonstrated

- RAII (Resource Acquisition Is Initialization)
- Move vs copy semantics
- `= delete` for ownership enforcement
- Destructor correctness
- Lifetime clarity
- Cross-platform C++ development with CMake

## Build Requirements

### Required

- **C++ compiler with C++20 support**
  - Windows: MSVC (Visual Studio Build Tools)
  - Linux: `g++` or `clang`
- **CMake 3.16 or newer**

## Installing CMake

### Windows

Download and install from:

- [CMake Download](https://cmake.org/download/)

Make sure **“Add CMake to PATH”** is enabled during installation.

Verify:

```bash
cmake --version
```

### Linux

```bash
sudo apt update
sudo apt install cmake build-essential
```

Verify:

```bash
cmake --version
```

## Build Instructions

1. Configure the project

   From the project root:

   ```bash
   cmake -S . -B build
   ```

2. Build

   ```bash
   cmake --build build
   ```

3. Run

   Windows

   ```bash
   build\Debug\cpp-raii-and-ownership.exe
   ```

   Linux

   ```bash
   ./build/cpp-raii-and-ownership
   ```

## Why This Project Exists

Game engines and UI frameworks abstract away lifetime and ownership.
This project demonstrates understanding of what those systems are built upon.
