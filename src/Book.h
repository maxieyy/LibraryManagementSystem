#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    int publicationYear;
    bool isAvailable;

public:

    Book(const std::string& title, const std::string& author, 
         const std::string& ISBN, int publicationYear);
    

    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    int getPublicationYear() const;
    bool getAvailability() const;
    

    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setISBN(const std::string& ISBN);
    void setPublicationYear(int year);
    

    void borrowBook();
    void returnBook();
    

    void displayInfo() const;
    

    bool operator==(const Book& other) const;
};

#endif 