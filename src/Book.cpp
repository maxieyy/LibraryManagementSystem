#include "Book.h"


Book::Book(const std::string& title, const std::string& author, 
           const std::string& ISBN, int publicationYear)
    : title(title), author(author), ISBN(ISBN), 
      publicationYear(publicationYear), isAvailable(true) {}


std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getISBN() const { return ISBN; }
int Book::getPublicationYear() const { return publicationYear; }
bool Book::getAvailability() const { return isAvailable; }


void Book::setTitle(const std::string& title) { this->title = title; }
void Book::setAuthor(const std::string& author) { this->author = author; }
void Book::setISBN(const std::string& ISBN) { this->ISBN = ISBN; }
void Book::setPublicationYear(int year) { publicationYear = year; }

// Book operations
void Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        std::cout << "Book '" << title << "' has been borrowed.\n";
    } else {
        std::cout << "Book '" << title << "' is not available for borrowing.\n";
    }
}

void Book::returnBook() {
    if (!isAvailable) {
        isAvailable = true;
        std::cout << "Book '" << title << "' has been returned.\n";
    } else {
        std::cout << "Book '" << title << "' was not borrowed.\n";
    }
}

// Display
void Book::displayInfo() const {
    std::cout << "\nBook Information\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Author: " << author << "\n";
    std::cout << "ISBN: " << ISBN << "\n";
    std::cout << "Publication Year: " << publicationYear << "\n";
    std::cout << "Status: " << (isAvailable ? "Available" : "Borrowed") << "\n";
}

// Comparison operator
bool Book::operator==(const Book& other) const {
    return this->ISBN == other.ISBN;
}