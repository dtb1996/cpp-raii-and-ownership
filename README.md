# cpp-raii-and-ownership

A focused C++ project demonstrating RAII, ownership semantics, and move-only resource management using modern C++ (C++20).

This repository is intentionally engine-agnostic and avoids frameworks to highlight core language understanding.

## Goals

- Demonstrate correct resource lifetime management
- Apply RAII principles consistently
- Implement move-only types
- Show understanding of the Rule of Five
- Avoid memory leaks and undefined behavior

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

## Build Instructions

- Open cpp-raii-and-ownership.sln in Visual Studio 2022
- Build in Debug or Release
- Run the console application

## Why This Project Exists

Game engines and UI frameworks abstract away lifetime and ownership.
This project demonstrates understanding of what those systems are built upon.
