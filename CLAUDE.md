# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is a C++ learning project for data structures and algorithms implementation. The project is primarily designed for educational purposes, suitable for both beginners and advanced learners who want to review and consolidate fundamental knowledge.

## Build and Development Environment

- **Compiler**: Visual Studio 2026 or compatible C++ development environment
- **Language**: C++ (with Chinese comments for educational purposes)
- **No Makefile**: Uses Visual Studio project files (.sln, .vcxproj) for building

### Common Commands

```bash
# Compile and run the main implementation
g++ -std=c++11 "data structures and algorithms.cpp" -o main && ./main

# Compile individual files for testing
g++ -std=c++11 "data structures and algorithms/linked list.cpp" -o linked_list && ./linked_list

# Run with Visual Studio
# Open the solution file and use F5 to build and run
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

- `data structures and algorithms.cpp`: Main file with array operations and dynamic array class
- `linked list.cpp`: Complete linked list implementation with friend functions
- `vector.cpp`: Template-based vector implementation (educational)
- `数组的增删改查.cpp`: Basic array CRUD operations
- `单链表逆序.cpp`: Linked list reversal exercises

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
2. Follow the existing pattern with clear Chinese comments
3. Include comprehensive test cases in main()
4. Use conditional compilation for different test scenarios