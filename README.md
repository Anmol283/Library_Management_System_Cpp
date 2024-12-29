# Library_Management_System_C++

## Overview

This project is a **Library Management System** that manages both physical and digital books. The system allows users to add, remove, and search books (both physical and digital) by their ISBN. The system tracks the total number of physical and digital books and provides functionality to display the details of each book. This project demonstrates the use of object-oriented programming concepts such as inheritance, static members, and polymorphism.

## Features

- **Book Management**: Add, remove, and search for books by ISBN.
- **Physical and Digital Books**: Differentiates between physical books and digital books (e-books).
- **Dynamic Book Count**: Keeps track of the total count of physical books and digital books.
- **Display Book Details**: Displays information about the book including title, author, ISBN, and availability.

## Functionalities

- **Add Books**: Allows adding new books to the system, including both physical and digital formats.
- **Remove Books**: Allows removing a book from the system by its ISBN.
- **Search Books**: Allows searching for books using the ISBN number and displaying details if found.
- **Book Count**: Displays the total number of physical and digital books in the library.

## Classes

- **Book Class**: Represents a physical book in the library with details such as title, author, ISBN, and availability. It also includes a static count of physical books.
- **digital_books Class**: Inherits from the Book class, representing digital books (e-books), and keeps a count of digital books separately.

## How to Use

1. Compile and run the program.
2. You will be prompted to select an operation (Add, Remove, or Search).
3. Depending on the operation:
    - **Add**: You will be asked to enter the title, author, ISBN, and availability status of the book.
    - **Remove**: You will be prompted to enter the ISBN of the book to be removed.
    - **Search**: Enter the ISBN of the book you want to search for, and the system will display its details if found.
4. After performing an operation, the system will display the updated list of books and the total count of physical and digital books.

## Example Usage

```cpp
what do you want to do?(A for add ,R for remove, S for search):
S
enter the ISBN of the book you want to search: 123
book found
Title: C++ Author: abc ISBN: 123 Available: Yes
```

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- Inheritance
- Static members
- Polymorphism

## Future Improvements

- Integrate file handling to save and load books data to/from a file.
- Implement a user interface for easier interaction.
- Add more features like book borrowing and returning.

