#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Book.h"
#include "User.h"

class Library {
private:
    std::vector<std::shared_ptr<Book>> books;
    std::vector<std::shared_ptr<User>> users;

public:
    // Book management
    void addBook(const std::string& title, const std::string& author, 
                 const std::string& ISBN, int year);
    bool removeBook(const std::string& ISBN);
    
    // Book search methods
    std::shared_ptr<Book> searchByTitle(const std::string& title) const;
    std::vector<std::shared_ptr<Book>> searchByAuthor(const std::string& author) const;
    std::shared_ptr<Book> searchByISBN(const std::string& ISBN) const;
    std::vector<std::shared_ptr<Book>> searchByYear(int year) const;
    
    // User management
    std::shared_ptr<User> registerUser(const std::string& name);
    bool removeUser(const std::string& userId);
    std::shared_ptr<User> findUserById(const std::string& userId) const;
    std::shared_ptr<User> findUserByName(const std::string& name) const;
    

    bool borrowBook(const std::string& userId, const std::string& ISBN);
    bool returnBook(const std::string& userId, const std::string& ISBN);
    

    void displayAllBooks() const;
    void displayAvailableBooks() const;
    void displayAllUsers() const;
    

    size_t getBookCount() const;
    size_t getUserCount() const;
    std::vector<std::shared_ptr<Book>> getAllBooks() const;
    std::vector<std::shared_ptr<User>> getAllUsers() const;
};

#endif 