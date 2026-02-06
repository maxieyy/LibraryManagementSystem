#include "User.h"
#include <iostream>

int User::userCount = 0;


User::User(const std::string& name) : name(name) {
    userCount++;
    userId = "U" + std::to_string(1000 + userCount);
}


std::string User::getUserId() const { return userId; }
std::string User::getName() const { return name; }
std::vector<std::shared_ptr<Book>> User::getBorrowedBooks() const { return borrowedBooks; }

// Borrow a book
bool User::borrowBook(std::shared_ptr<Book> book) {
    if (!book->getAvailability()) {
        std::cout << "Book is not available for borrowing.\n";
        return false;
    }
    
    borrowedBooks.push_back(book);
    book->borrowBook();
    return true;
}

// Return a book
bool User::returnBook(const std::string& ISBN) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if ((*it)->getISBN() == ISBN) {
            (*it)->returnBook();
            borrowedBooks.erase(it);
            return true;
        }
    }
    std::cout << "You haven't borrowed a book with ISBN: " << ISBN << "\n";
    return false;
}

// user info
void User::displayInfo() const {
    std::cout << "\nser Information \n";
    std::cout << "User ID: " << userId << "\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Books Borrowed: " << borrowedBooks.size() << "\n";

}

// borrowed books
void User::displayBorrowedBooks() const {
    if (borrowedBooks.empty()) {
        std::cout << "No books borrowed.\n";
        return;
    }
    
    std::cout << "\nBorrowed Books\n";
    for (const auto& book : borrowedBooks) {
        std::cout << "- " << book->getTitle() << " (ISBN: " << book->getISBN() << ")\n";
    }

}

// Check if user has borrowed a specific book
bool User::hasBorrowedBook(const std::string& ISBN) const {
    for (const auto& book : borrowedBooks) {
        if (book->getISBN() == ISBN) {
            return true;
        }
    }
    return false;
}


bool User::operator==(const User& other) const {
    return this->userId == other.userId;
}