📚 Library Management System in C++


A console-based Library Management System built using Object-Oriented Programming in C++ that allows you to:

Add books 📘

Add students 👨‍🎓

Issue books to students 📖➡️👨‍🎓

This system demonstrates effective usage of classes, inheritance, static members, and standard containers (std::vector) with proper input validation and modular design.

✨ Features

🔹 Book Management

Add new books with details like Accession Number, Title, Author, Price, and Number of Copies.

Tracks total number of books using a static variable.

Displays complete information about each book.

🔹 Student Management

Register students with details like Registration Number, Name, Course, and Semester.

Tracks total number of registered students.

Verifies student existence before issuing books.

🔹 Book Issuing System

Inherits from Book class.

Allows issuing books to students only if copies are available and the student is registered.

Tracks which student has been issued which book using a vector of registration numbers.

🧠 OOP Concepts Used

Encapsulation: Separate classes for Book, Student, and IssueBook.

Inheritance: IssueBook inherits from Book.

Static Members: Track total books and students.

Polymorphism: Method overriding for showDetails() in derived class.

Robust Input Handling: Validates numeric entries with std::cin safeguards.

🛠️ How to Run

✅ Prerequisites

A C++ compiler like G++ or an IDE like CodeBlocks, Visual Studio, or Dev-C++.

🔄 Compile and Run
bash
Copy
Edit
g++ -std=c++11 -o library_system library_system.cpp
./library_system
🗂️ Project Structure
bash
Copy
Edit
📁 library_system/
├── library_system.cpp   # Main C++ source file
└── README.md            # Project documentation
🧪 Sample Menu Flow
txt
Copy
Edit
1. Add new Book
2. Add new Student
3. Issue Book
4. Exit
Each option leads you through an interactive input process.

📦 Data Flow Overview
mermaid
Copy
Edit
graph TD
A[User] -->|Inputs| B[Main Menu]
B --> C[Add Book]
B --> D[Add Student]
B --> E[Issue Book]
C --> F[Books Vector]
D --> G[Students Vector]
E --> H[IssueBook + Validation]
📈 Future Improvements
📌 Add persistent file storage using file I/O

📌 Implement return functionality and fine calculation

📌 Add GUI using C++ frameworks or port to Web using Node.js

🧑‍💻 Author
Satwik Mohanty
🔗 GitHub Profile
💼 Passionate about full-stack development & system design

💖 Show Some Love
If you found this project helpful, consider giving it a ⭐ on GitHub and feel free to fork and contribute!

