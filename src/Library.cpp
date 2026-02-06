#include "Library.h"
#include <iostream>
#include <iomanip>


void Library::addBook(const std::string& title, const std::string& author, 
                      const std::string& ISBN, int year) {

    for (const auto& book : books) {
        if (book->getISBN() == ISBN) {
            std::cout << "Book with ISBN " << ISBN << " already exists!\n";
            return;
        }
    }
    
    auto newBook = std::make_shared<Book>(title, author, ISBN, year);
    books.push_back(newBook);
    std::cout << "Book '" << title << "' added successfully.\n";
}


bool Library::removeBook(const std::string& ISBN) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getISBN() == ISBN) {

            if (!(*it)->getAvailability()) {
                std::cout << "Cannot remove book. It is currently borrowed.\n";
                return false;
            }
            books.erase(it);
            std::cout << "Book removed successfully.\n";
            return true;
        }
    }
    std::cout << "Book with ISBN " << ISBN << " not found.\n";
    return false;
}

// Search by title
std::shared_ptr<Book> Library::searchByTitle(const std::string& title) const {
    for (const auto& book : books) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;
}

// Search by author
std::vector<std::shared_ptr<Book>> Library::searchByAuthor(const std::string& author) const {
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& book : books) {
        if (book->getAuthor() == author) {
            result.push_back(book);
        }
    }
    return result;
}

// Search by ISBN
std::shared_ptr<Book> Library::searchByISBN(const std::string& ISBN) const {
    for (const auto& book : books) {
        if (book->getISBN() == ISBN) {
            return book;
        }
    }
    return nullptr;
}

// Search by publication year
std::vector<std::shared_ptr<Book>> Library::searchByYear(int year) const {
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& book : books) {
        if (book->getPublicationYear() == year) {
            result.push_back(book);
        }
    }
    return result;
}

// Register a new user
std::shared_ptr<User> Library::registerUser(const std::string& name) {
    auto newUser = std::make_shared<User>(name);
    users.push_back(newUser);
    std::cout << "User '" << name << "' registered successfully. User ID: " 
              << newUser->getUserId() << "\n";
    return newUser;
}

// Remove a user
bool Library::removeUser(const std::string& userId) {
    for (auto it = users.begin(); it != users.end(); ++it) {
        if ((*it)->getUserId() == userId) {

            if (!(*it)->getBorrowedBooks().empty()) {
                std::cout << "Cannot remove user. They have borrowed books.\n";
                return false;
            }
            users.erase(it);
            std::cout << "User removed successfully.\n";
            return true;
        }
    }
    std::cout << "User with ID " << userId << " not found.\n";
    return false;
}

// Find user by ID
std::shared_ptr<User> Library::findUserById(const std::string& userId) const {
    for (const auto& user : users) {
        if (user->getUserId() == userId) {
            return user;
        }
    }
    return nullptr;
}

// Find user by name
std::shared_ptr<User> Library::findUserByName(const std::string& name) const {
    for (const auto& user : users) {
        if (user->getName() == name) {
            return user;
        }
    }
    return nullptr;
}

// Borrow a book
bool Library::borrowBook(const std::string& userId, const std::string& ISBN) {
    auto user = findUserById(userId);
    if (!user) {
        std::cout << "User not found.\n";
        return false;
    }
    
    auto book = searchByISBN(ISBN);
    if (!book) {
        std::cout << "Book not found.\n";
        return false;
    }
    
    return user->borrowBook(book);
}

// Return a book
bool Library::returnBook(const std::string& userId, const std::string& ISBN) {
    auto user = findUserById(userId);
    if (!user) {
        std::cout << "User not found.\n";
        return false;
    }
    
    return user->returnBook(ISBN);
}


void Library::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "No books in the library.\n";
        return;
    }
    
    std::cout << "\nAll Books in Libraryn";
    std::cout << std::left << std::setw(20) << "Title" 
              << std::setw(20) << "Author" 
              << std::setw(15) << "ISBN" 
              << std::setw(10) << "Year" 
              << std::setw(12) << "Status" << "\n";
    std::cout << std::string(77, '-') << "\n";
    
    for (const auto& book : books) {
        std::cout << std::left << std::setw(20) << book->getTitle() 
                  << std::setw(20) << book->getAuthor() 
                  << std::setw(15) << book->getISBN() 
                  << std::setw(10) << book->getPublicationYear() 
                  << std::setw(12) << (book->getAvailability() ? "Available" : "Borrowed") 
                  << "\n";
    }
    std::cout << "Total Books: " << books.size() << "\n";
}


void Library::displayAvailableBooks() const {
    std::cout << "\n=== Available Books ===\n";
    bool found = false;
    
    for (const auto& book : books) {
        if (book->getAvailability()) {
            std::cout << "- " << book->getTitle() << " by " << book->getAuthor() 
                      << " (ISBN: " << book->getISBN() << ")\n";
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No available books at the moment.\n";
    }
}


void Library::displayAllUsers() const {
    if (users.empty()) {
        std::cout << "No registered users.\n";
        return;
    }
    
    std::cout << "\nRegistered Users\n";
    for (const auto& user : users) {
        std::cout << "- ID: " << user->getUserId() 
                  << ", Name: " << user->getName() 
                  << ", Books Borrowed: " << user->getBorrowedBooks().size() << "\n";
    }
}


size_t Library::getBookCount() const { return books.size(); }
size_t Library::getUserCount() const { return users.size(); }
std::vector<std::shared_ptr<Book>> Library::getAllBooks() const { return books; }
std::vector<std::shared_ptr<User>> Library::getAllUsers() const { return users; }