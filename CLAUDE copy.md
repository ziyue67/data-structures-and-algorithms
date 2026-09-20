# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ learning project for data structures and algorithms implementation. The project is primarily designed for educational purposes, suitable for both beginners and advanced learners who want to review and consolidate fundamental knowledge.

## Build and Development Environment

- **Compiler**: Visual Studio 2022/2026 or compatible C++ development environment
- **Language**: C++20 (primary), with C++11 support for some configurations
- **Project Format**: Visual Studio solution (.slnx) and project files (.vcxproj)
- **Platforms**: Supports both Win32 (x86) and x64 architectures
- **External Dependencies**: Ctoon library (optional, referenced but not required for core functionality)

### Common Commands

```bash
# Compile and run the main implementation (g++)
g++ -std=c++20 "data structures and algorithms/data structures and algorithms.cpp" -o main && ./main

# Compile individual files for testing
g++ -std=c++20 "data structures and algorithms/linked list.cpp" -o linked_list && ./linked_list
g++ -std=c++20 "data structures and algorithms/数组的增删改查.cpp" -o array_ops && ./array_ops

# Run with Visual Studio
# Open "data structures and algorithms.slnx" and use F5 to build and run
# Build configurations available: Debug/Release for both Win32 and x64

# Build with CMake (for ctoon example, when ctoon library is available)
cd ctoon_example && cmake -B build && cmake --build build
```

## Code Architecture

### Main Components

1. **Array Implementation** (`data structures and algorithms.cpp`)
   - Basic array operations (insert, delete, search, reverse)
   - Dynamic Array class with automatic capacity expansion
   - Demonstrates O(1) amortized push_back, O(n) insert/erase operations

2. **Linked List Implementation** (`linked list.cpp`)
   - Singly linked list with head node
   - Operations: insertHead, insertTail, remove, reverse, find
   - Friend functions for merging sorted lists and finding kth node from end

3. **Vector Template Class** (`vector.cpp`)
   - Complete STL-like vector implementation (commented out)
   - Template-based design supporting any data type
   - Full iterator support for range-based for loops

### Code Structure Patterns

- **Learning-Oriented Design**: Code contains extensive Chinese comments explaining concepts
- **Progressive Complexity**: Starts with basic array operations, moves to complex data structures
- **Multiple Implementation Examples**: Different approaches to the same problem (e.g., array reverse using different pointer techniques)
- **Conditional Compilation**: Uses `#if 0` blocks to enable/disable different sections for testing

### Key Files

- `data structures and algorithms/data structures and algorithms.cpp`: Main file with array operations and dynamic array class
- `data structures and algorithms/linked list.cpp`: Complete linked list implementation with friend functions
- `data structures and algorithms/vector.cpp`: Template-based vector implementation (educational, commented out)
- `data structures and algorithms/数组的增删改查.cpp`: Basic array CRUD operations in Chinese
- `data structures and algorithms/单链表逆序.cpp`: Linked list reversal exercises
- `data structures and algorithms/复盘.cpp`: Review and summary exercises
- `data structures and algorithms/[1-3].cpp`: Additional coding exercise files
- `data structures and algorithms.slnx`: Visual Studio solution file
- `ctoon_example/CMakeLists.txt`: CMake example for optional ctoon library integration

## Development Guidelines

### Testing Approach

- Use conditional compilation (`#if 0`/`#if 1`) to test different sections
- Each main() function contains multiple test scenarios
- Random number generation for creating test data

### Code Style

- Chinese comments for educational clarity
- Clear separation between interface and implementation
- Memory management with explicit delete operations
- Proper use of pointers and references

### Adding New Implementations

When adding new data structures or algorithms:
1. Create a new .cpp file in the `data structures and algorithms/` directory
2. Follow the existing pattern with clear Chinese comments for educational purposes
3. Include comprehensive test cases in main() using conditional compilation (`#if 0`/`#if 1`)
4. Add the new file to the Visual Studio project file (.vcxproj) if using IDE builds
5. Use consistent naming conventions (prefer Chinese filenames for educational content)

### Project Structure Notes

- **Source Organization**: All main implementation files are in the `data structures and algorithms/` subdirectory
- **Bilingual Content**: Mix of English and Chinese ( filenames and comments for learning purposes)
- **Optional Dependencies**: Ctoon library headers are referenced but not required for core functionality
- **Multi-platform**: While primarily designed for Windows/Visual Studio, can be compiled with g++ on other platforms
- **Educational Focus**: Code emphasizes clarity and learning over performance optimization