# Library Management System (C++)

A simple console-based Library Management System built with C++ using Object-Oriented Programming (OOP) concepts and STL.

## Features

- Add new books
- Display all books
- Search books by ID
- Borrow books
- Return books
- Delete books
- Input validation for numeric IDs
- Support for book titles and author names with spaces

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL Vector
- String Handling
- Input Validation

## Project Structure

```cpp
class Book
{
    int id;
    string title;
    string author;
    string status;
};
```

Books are stored using:

```cpp
vector<Book>
```

## Example Menu

```text
1) Add Book
2) Show All Books
3) Search By ID
4) Borrow Book
5) Return Book
6) Delete Book
7) Exit
```

## What I Learned

Through this project I practiced:

- Classes and Objects
- Member Functions
- Passing Objects by Reference
- STL Vector
- Loops and Conditions
- User Input Validation
- Basic Project Organization

## Future Improvements

- Separate Library class from Book class
- Use Constructors
- Apply Encapsulation (private/public)
- Save data using files
- Improve status handling with enums

## Author

Abdallah Mohammed

Computer Science Student
This project was built as part of my C++ learning journey.
