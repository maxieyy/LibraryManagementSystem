# 📚 Online Library Management System

## Overview
A C++ implementation of an Online Library Management System using Object-Oriented Programming principles. it will allow managing books, users, and borrowing/returning operations.

## Features
 - **Book Management**: Add, remove, search, and display books
 - **User Management**: Register, remove, and manage users
 - **Borrowing System**: Borrow and return books with availability checks
 - **Search Functionality**: Search books by title, author, ISBN, or year
 - **Comprehensive Testing**: Unit tests for all core functionalities

## Class Design
### Book Class
- Attributes: title, author, ISBN, publicationYear, isAvailable
- Methods: borrowBook(), returnBook(), displayInfo()

### User Class
- Attributes: userId, name, borrowedBooks
- Methods: borrowBook(), returnBook(), displayInfo()

### Library Class
- Manages collections of books and users
- Provides search, borrowing, and returning operations

## Prerequisites
- C++ Compiler (g++ 11 or later)
- CMake (optional, for building)
- Git (for version control)

## Building and Running

### Method 1: Using g++ directly
```bash
# Compile the main program
g++ -std=c++11 src/*.cpp -I src -o library_system

# Run the program
./library_system

# Compile and run tests
g++ -std=c++11 src/*.cpp tests/test_main.cpp -I src -o test_system
./test_system