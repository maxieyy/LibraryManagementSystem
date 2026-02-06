#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include "Book.h"

class User {
private:
    std::string userId;
    std::string name;
    std::vector<std::shared_ptr<Book>> borrowedBooks;
    static int userCount;

public:

    User(const std::string& name);
    

    std::string getUserId() const;
    std::string getName() const;
    std::vector<std::shared_ptr<Book>> getBorrowedBooks() const;
    

    bool borrowBook(std::shared_ptr<Book> book);
    bool returnBook(const std::string& ISBN);
    

    void displayInfo() const;
    void displayBorrowedBooks() const;
    
    // Check if user has borrowed a specific book
    bool hasBorrowedBook(const std::string& ISBN) const;
    

    bool operator==(const User& other) const;
};

#endif 