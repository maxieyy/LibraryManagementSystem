#include <iostream>
#include <memory>
#include "Library.h"

void displayMenu() {
    std::cout << "\n Online Library Management System \n";
    std::cout << "1. Add a Book\n";
    std::cout << "2. Remove a Book\n";
    std::cout << "3. Search for Books\n";
    std::cout << "4. Display All Books\n";
    std::cout << "5. Display Available Books\n";
    std::cout << "6. Register a User\n";
    std::cout << "7. Remove a User\n";
    std::cout << "8. Display All Users\n";
    std::cout << "9. Borrow a Book\n";
    std::cout << "10. Return a Book\n";
    std::cout << "11. Exit\n";
    std::cout << "Enter your choice (1-11): ";
}

void searchMenu(Library& library) {
    int choice;
    std::cout << "1. Search by Title\n";
    std::cout << "2. Search by Author\n";
    std::cout << "3. Search by ISBN\n";
    std::cout << "4. Search by Year\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();
    
    std::string query;
    int year;
    
    switch(choice) {
        case 1: {
            std::cout << "Enter title: ";
            std::getline(std::cin, query);
            auto book = library.searchByTitle(query);
            if (book) {
                book->displayInfo();
            } else {
                std::cout << "Book not found.\n";
            }
            break;
        }
        case 2: {
            std::cout << "Enter author: ";
            std::getline(std::cin, query);
            auto books = library.searchByAuthor(query);
            if (!books.empty()) {
                std::cout << "\nFound " << books.size() << " book(s):\n";
                for (const auto& book : books) {
                    book->displayInfo();
                }
            } else {
                std::cout << "No books found by this author.\n";
            }
            break;
        }
        case 3: {
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, query);
            auto book = library.searchByISBN(query);
            if (book) {
                book->displayInfo();
            } else {
                std::cout << "Book not found.\n";
            }
            break;
        }
        case 4: {
            std::cout << "Enter publication year: ";
            std::cin >> year;
            auto books = library.searchByYear(year);
            if (!books.empty()) {
                std::cout << "\nFound " << books.size() << " book(s):\n";
                for (const auto& book : books) {
                    book->displayInfo();
                }
            } else {
                std::cout << "No books found from this year.\n";
            }
            break;
        }
        default:
            std::cout << "Invalid choice.\n";
    }
}

int main() {
    Library library;
    

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", 1925);
    library.addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084", 1960);
    library.addBook("1984", "George Orwell", "9780451524935", 1949);
    library.addBook("Pride and Prejudice", "Jane Austen", "9780141439518", 1813);
    
    library.registerUser("John Doe");
    library.registerUser("Jane Smith");
    
    int choice;
    std::string title, author, ISBN, name, userId;
    int year;
    
    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch(choice) {
            case 1: {
                std::cout << "Enter book title: ";
                std::getline(std::cin, title);
                std::cout << "Enter author: ";
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, ISBN);
                std::cout << "Enter publication year: ";
                std::cin >> year;
                library.addBook(title, author, ISBN, year);
                break;
            }
            case 2: {
                std::cout << "Enter ISBN of book to remove: ";
                std::getline(std::cin, ISBN);
                library.removeBook(ISBN);
                break;
            }
            case 3:
                searchMenu(library);
                break;
            case 4:
                library.displayAllBooks();
                break;
            case 5:
                library.displayAvailableBooks();
                break;
            case 6: {
                std::cout << "Enter user name: ";
                std::getline(std::cin, name);
                library.registerUser(name);
                break;
            }
            case 7: {
                std::cout << "Enter user ID to remove: ";
                std::getline(std::cin, userId);
                library.removeUser(userId);
                break;
            }
            case 8:
                library.displayAllUsers();
                break;
            case 9: {
                std::cout << "Enter user ID: ";
                std::getline(std::cin, userId);
                std::cout << "Enter ISBN of book to borrow: ";
                std::getline(std::cin, ISBN);
                library.borrowBook(userId, ISBN);
                break;
            }
            case 10: {
                std::cout << "Enter user ID: ";
                std::getline(std::cin, userId);
                std::cout << "Enter ISBN of book to return: ";
                std::getline(std::cin, ISBN);
                library.returnBook(userId, ISBN);
                break;
            }
            case 11:
                std::cout << "Thank you for using the Library Management System!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 11);
    
    return 0;
}