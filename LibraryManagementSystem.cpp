#include <iostream>
#include <string>
#include <vector>
#include <limits> // For std::numeric_limits
using namespace std;

// Book class to store details about a book
class Book {
public:
    int AccNo;          // Accession Number of the book
    std::string title;  // Title of the book
    std::string author; // Author of the book
    int price;          // Price of the book
    int numCopies;      // Number of copies available in the library
    static int totalBook; // Total number of books in the library

    // Constructor to initialize data members
    Book() : AccNo(0), price(0), numCopies(0) {}

    // Method to input details of the book
    void setDetails() {
        std::cout << "Enter the Accession No: ";
        while (!(std::cin >> AccNo)) {
            std::cout << "Invalid input. Please enter a valid integer for Accession No: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // To ignore the newline character after integer input
        std::cout << "Enter the Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter the Author: ";
        std::getline(std::cin, author);
        std::cout << "Enter the Price: ";
        while (!(std::cin >> price)) {
            std::cout << "Invalid input. Please enter a valid integer for Price: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Enter the Number of Copies: ";
        while (!(std::cin >> numCopies)) {
            std::cout << "Invalid input. Please enter a valid integer for Number of Copies: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        totalBook++; // Increment the total number of books
    }

    // Method to display details of the book
    void showDetails() const {
        std::cout << "Accession Number: " << AccNo << "\n"
                  << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "Price: " << price << "\n"
                  << "Number of Copies Available: " << numCopies << "\n";
    }

    // Static method to get the total number of books
    static int getTotalBook() {
        return totalBook;
    }
};

int Book::totalBook = 0; // Initialize static member totalBook

// Student class to store details about a student
class Student {
public:
    int regdNo;           // Registration Number of the student
    std::string Name;     // Name of the student
    std::string course;   // Course of the student
    int semester;         // Semester of the student
    static int totalStudent; // Total number of students

    // Constructor to initialize data members
    Student() : regdNo(0), semester(0) {}

    // Method to input details of the student
    void createStudent() {
        std::cout << "Enter the Registration No: ";
        while (!(std::cin >> regdNo)) {
            std::cout << "Invalid input. Please enter a valid integer for Registration No: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(); // To ignore the newline character after integer input
        std::cout << "Enter the Name: ";
        std::getline(std::cin, Name);
        std::cout << "Enter the Course: ";
        std::getline(std::cin, course);
        std::cout << "Enter the Semester: ";
        while (!(std::cin >> semester)) {
            std::cout << "Invalid input. Please enter a valid integer for Semester: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        totalStudent++; // Increment the total number of students
    }

    // Method to display details of the student
    void showStudentDetails() const {
        std::cout << "Registration Number: " << regdNo << "\n"
                  << "Name: " << Name << "\n"
                  << "Course: " << course << "\n"
                  << "Semester: " << semester << "\n";
    }

    // Method to search for a student by registration number
    bool searchStudent(const std::vector<Student>& students, int regdNo) const {
        for (const auto& student : students) {
            if (student.regdNo == regdNo) {
                std::cout << "The Registration No. is valid...\n";
                student.showStudentDetails();
                return true;
            }
        }
        std::cout << "The Registration No. is invalid...\n";
        return false;
    }
};

int Student::totalStudent = 0; // Initialize static member totalStudent

// IssueBook class inheriting from Book to handle book issuing
class IssueBook : public Book {
public:
    std::vector<int> assignedStudents; // Vector to store registration numbers of students to whom the book is assigned

    // Constructor to initialize data members
    IssueBook() : Book() {}

    // Method to input details of the book
    void setDetails() {
        Book::setDetails(); // Call base class method to set book details
    }

    // Method to display details of the book and the students it's assigned to
    void showDetails() const {
        Book::showDetails(); // Call base class method to show book details
        std::cout << "Assigned to Students: ";
        if (assignedStudents.empty()) {
            std::cout << "None";
        } else {
            for (int regdNo : assignedStudents) {
                std::cout << regdNo << " ";
            }
        }
        std::cout << "\n";
    }

    // Method to search for a book by Accession Number
    bool searchBook(const std::vector<IssueBook>& books, int AccNo) const {
        for (const auto& book : books) {
            if (book.AccNo == AccNo) {
                std::cout << "The book is available in the list...\n";
                book.showDetails();
                return true;
            }
        }
        std::cout << "The book is not available in the list...\n";
        return false;
    }

    // Method to issue a book to a student if available
    void issueBook(std::vector<IssueBook>& books, int AccNo, const std::vector<Student>& students, int regdNo) {
        bool bookFound = false;

        for (auto& book : books) {
            if (book.AccNo == AccNo) {
                bookFound = true;

                if (book.numCopies <= 0) {
                    std::cout << "The book is available in the library but no copies left. All copies are assigned.\n";
                    return;
                }

                // Check if the student exists before assigning the book
                Student student;
                bool studentExists = student.searchStudent(students, regdNo);
                if (studentExists) {
                    book.assignedStudents.push_back(regdNo);
                    book.numCopies--; // Decrement the number of copies available
                    std::cout << "Book is successfully issued to " << regdNo << "\n";
                }
                return; // Return after issuing or finding that the student does not exist
            }
        }

        if (!bookFound) {
            std::cout << "The book does not exist in the list...\n";
        }
    }
};

// Function to add books to the library
void addBooks(std::vector<IssueBook>& books) {
    char choice = 'y';
    while (choice != 'n') {
        IssueBook book;
        book.setDetails();
        books.push_back(book); // Add the book to the vector
        std::cout << "Do you want to add another book? (Y/N): ";
        std::cin >> choice;
    }
}

// Function to add students to the library system
void addStudents(std::vector<Student>& students) {
    char choice = 'y';
    while (choice != 'n') {
        Student student;
        student.createStudent();
        students.push_back(student); // Add the student to the vector
        std::cout << "Do you want to add another student? (Y/N): ";
        std::cin >> choice;
    }
}

// Function to issue books to students
void issueBook(std::vector<IssueBook>& books, std::vector<Student>& students) {
    char choice = 'y';
    while (choice != 'n') {
        int AccNo, regdNo;
        std::cout << "Enter the Accession No: ";
        while (!(std::cin >> AccNo)) {
            std::cout << "Invalid input. Please enter a valid integer for Accession No: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "Enter the Registration No of student: ";
        while (!(std::cin >> regdNo)) {
            std::cout << "Invalid input. Please enter a valid integer for Registration No: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Issue the book to the student
        for (auto& issueBook : books) {
            if (issueBook.AccNo == AccNo) {
                issueBook.issueBook(books, AccNo, students, regdNo);
                break; // Exit the loop once the book is found and processed
            }
        }

        std::cout << "Do you want to issue another book? (Y/N): ";
        std::cin >> choice;
    }
}

// Main function to drive the library management system
int main() {
    std::vector<IssueBook> books;  // Vector to store books
    std::vector<Student> students;   // Vector to store students

    int choice = 0; // Variable to store user choice

    // Main menu loop
    while (choice != 4) {
        std::cout << "1. Add new Book\n2. Add new Student\n3. Issue Book\n4. Exit\n";
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid integer for your choice: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1:
                addBooks(books);
                break;
            case 2:
                addStudents(students);
                break;
            case 3:
                issueBook(books, students);
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid input. Please select a valid option.\n";
        }
    }
    return 0; // End of the program
}

