#include<iostream>
#include<string>
using namespace std;

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

// Function to print a separator line
void printSeparator() {
    cout << GREEN << "==================================================" << RESET << endl;
}

// Function to print the welcome banner
void printBanner() {
    printSeparator();
    cout << CYAN << "  _        __  __      _____ " << RESET << endl;
    cout << CYAN << " | |      |  \\/  |    / ____|" << RESET << endl;
    cout << CYAN << " | |      | |\\/| |   | (___  " << RESET << endl;
    cout << CYAN << " | |      | |  | |    \\___ \\ " << RESET << endl;
    cout << CYAN << " | |___   | |  | |    ____) |" << RESET << endl;
    cout << CYAN << " |_____|  |_|  |_|   |_____/ " << RESET << endl;
    printSeparator();
    cout << YELLOW << "LIBRARY MANAGEMENT SYSTEM" << RESET << endl;
    cout << MAGENTA << "Developed by:- Anmol" << RESET << endl;
}

class Book {
protected:
    string title;
    string author;
    int ISBN;
    bool availability;
    static int count;
public:
    Book(string title, string author, int ISBN, bool availability) {
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->availability = availability;
        count++;
    }
    ~Book() {
        count--;
    }
    virtual void display_Book() {
        cout << YELLOW << "Title: " << title 
             << ", Author: " << author 
             << ", ISBN: " << ISBN 
             << ", Available: " << (availability ? GREEN "Yes" : RED "No") 
             << RESET << endl;
    }
    static void display_count() {
        cout << BLUE << BOLD << "Total Physical Books in Library: " << count << RESET << endl;
    }
    bool search_book(int search_ISBN) {
        if (search_ISBN == ISBN) {
            return true;
        }
        return false;
    }
};

int Book::count = 0;

class digital_books : public Book {
    static int count_db;
public:
    digital_books(string title, string author, int ISBN, bool availability) 
        : Book(title, author, ISBN, availability) {
        count_db++;
        count--;
    }
    ~digital_books() {
        count_db--;
    }
    void display_Book() override {
        cout << MAGENTA << "E-book Title: " << title 
             << ", E-book Author: " << author 
             << ", E-book ISBN: " << ISBN 
             << ", E-book Available: " << (availability ? GREEN "Yes" : RED "No") 
             << RESET << endl;
    }
    static void display_count() {
        cout << BLUE << BOLD << "Total Digital Books: " << count_db << RESET << endl;
    }
};

int digital_books::count_db = 0;

int main() {
    // Initialize books
    Book *b1 = new Book("C++", "abc", 123, true);
    Book *b2 = new Book("python", "xyz", 456, true);
    Book *b3 = new Book("C", "pqr", 789, true);
    digital_books *db1 = new digital_books("E-book Java", "xyz", 789, true);
    digital_books *db2 = new digital_books("E-book javascript", "abc", 456, true);

    // Display welcome banner
    printBanner();

    // Display all books
    cout << CYAN << BOLD << "Current Library Collection:" << RESET << endl;
    b1->display_Book();
    b2->display_Book();
    b3->display_Book();
    db1->display_Book();
    db2->display_Book();
    printSeparator();

    // Display book counts
    Book::display_count();
    digital_books::display_count();
    printSeparator();

    // User input for action
    char function;
    cout << YELLOW << BOLD << "What would you like to do?" << RESET << endl;
    cout << GREEN << "[A] Add a new book" << RESET << endl;
    cout << RED << "[R] Remove a book" << RESET << endl;
    cout << BLUE << "[S] Search for a book" << RESET << endl;
    cout << YELLOW << "Enter your choice (A/R/S): " << RESET;
    cin >> function;
    printSeparator();

    if (function == 'S') {
        int search_ISBN;
        cout << BLUE << "Enter the ISBN of the book to search: " << RESET;
        cin >> search_ISBN;
        if (b1->search_book(search_ISBN)) {
            cout << GREEN << "Book found!" << RESET << endl;
            b1->display_Book();
        }
        else if (b2->search_book(search_ISBN)) {
            cout << GREEN << "Book found!" << RESET << endl;
            b2->display_Book();
        }
        else if (b3->search_book(search_ISBN)) {
            cout << GREEN << "Book found!" << RESET << endl;
            b3->display_Book();
        }
        else {
            cout << RED << "Book not found!" << RESET << endl;
        }
    }
    else if (function == 'A') {
        string title, author;
        int ISBN;
        bool availability;
        cout << GREEN << "Adding a new book" << RESET << endl;
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter ISBN: ";
        cin >> ISBN;
        cout << "Enter availability (1 for Yes, 0 for No): ";
        cin >> availability;
        Book *b4 = new Book(title, author, ISBN, availability);
        cout << GREEN << "BOOK ADDED SUCCESSFULLY!" << RESET << endl;
        printSeparator();
        cout << CYAN << BOLD << "Updated Library Collection:" << RESET << endl;
        b1->display_Book();
        b2->display_Book();
        b3->display_Book();
        b4->display_Book();
        b4->display_count();
        delete b4; // Clean up newly added book
    }
    else if (function == 'R') {
        int remove_ISBN;
        cout << RED << "Enter the ISBN of the book to remove: " << RESET;
        cin >> remove_ISBN;
        if (b1->search_book(remove_ISBN)) {
            cout << GREEN << "Book removed successfully!" << RESET << endl;
            delete b1;
            b1 = nullptr;
            Book::display_count();
            if (b2) b2->display_Book();
            if (b3) b3->display_Book();
        }
        else if (b2->search_book(remove_ISBN)) {
            cout << GREEN << "Book removed successfully!" << RESET << endl;
            delete b2;
            b2 = nullptr;
            Book::display_count();
            if (b1) b1->display_Book();
            if (b3) b3->display_Book();
        }
        else if (b3->search_book(remove_ISBN)) {
            cout << GREEN << "Book removed successfully!" << RESET << endl;
            delete b3;
            b3 = nullptr;
            Book::display_count();
            if (b1) b1->display_Book();
            if (b2) b2->display_Book();
        }
        else {
            cout << RED << "BOOK NOT FOUND!" << RESET << endl;
        }
    }
    else {
        cout << RED << "Invalid choice! Please select A, R, or S." << RESET << endl;
    }

    // Clean up memory
    if (b1) delete b1;
    if (b2) delete b2;
    if (b3) delete b3;
    delete db1;
    delete db2;

    printSeparator();
    cout << GREEN << BOLD << "Thank you for using the Library Management System!" << RESET << endl;
    printSeparator();

    return 0;
}
