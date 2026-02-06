#include <iostream>
#include <cassert>
#include "../src/Library.h"

void runAllTests() {
    std::cout << " Running Library Management System Tests \n";
    
    Library lib;
    
    // Add books
    std::cout << "\nTest 1: Adding books...\n";
    lib.addBook("Test Book 1", "Author 1", "ISBN001", 2020);
    lib.addBook("Test Book 2", "Author 2", "ISBN002", 2021);
    assert(lib.getBookCount() == 2);
    std::cout << "✓ Added 2 books successfully\n";
    
    // Test 2: Add duplicate book
    std::cout << "\nTest 2: Adding duplicate book...\n";
    lib.addBook("Test Book 1", "Author 1", "ISBN001", 2020);
    assert(lib.getBookCount() == 2); 
    std::cout << "✓ Prevented duplicate book addition\n";
    
    // Test 3: Search by ISBN
    std::cout << "\nTest 3: Searching by ISBN...\n";
    auto book = lib.searchByISBN("ISBN001");
    assert(book != nullptr);
    assert(book->getTitle() == "Test Book 1");
    std::cout << "✓ Found book by ISBN\n";
    
    // Test 4: Search non-existent book
    std::cout << "\nTest 4: Searching non-existent book...\n";
    book = lib.searchByISBN("NONEXISTENT");
    assert(book == nullptr);
    std::cout << "✓ Correctly handled non-existent book\n";
    
    // Test 5: Register user
    std::cout << "\nTest 5: Registering user...\n";
    auto user = lib.registerUser("Test User");
    assert(user != nullptr);
    assert(lib.getUserCount() == 1);
    std::cout << "✓ User registered successfully\n";
    
    // Borrow book
    std::cout << "\nTest 6: Borrowing book...\n";
    bool borrowSuccess = lib.borrowBook(user->getUserId(), "ISBN001");
    assert(borrowSuccess == true);
    book = lib.searchByISBN("ISBN001");
    assert(book->getAvailability() == false);
    std::cout << "✓ Book borrowed successfully\n";
    

    std::cout << "\nTest 7: Borrowing unavailable book...\n";
    auto user2 = lib.registerUser("Test User 2");
    borrowSuccess = lib.borrowBook(user2->getUserId(), "ISBN001");
    assert(borrowSuccess == false); 
    std::cout << "✓ Prevented borrowing unavailable book\n";
    

    std::cout << "\nTest 8: Returning book...\n";
    bool returnSuccess = lib.returnBook(user->getUserId(), "ISBN001");
    assert(returnSuccess == true);
    book = lib.searchByISBN("ISBN001");
    assert(book->getAvailability() == true);
    std::cout << "✓ Book returned successfully\n";
    

    std::cout << "\nTest 9: Removing borrowed book...\n";
    lib.borrowBook(user->getUserId(), "ISBN001");
    bool removeSuccess = lib.removeBook("ISBN001");
    assert(removeSuccess == false); 
    std::cout << "✓ Prevented removal of borrowed book\n";
    

    std::cout << "\nTest 10: Removing user with borrowed books...\n";
    bool userRemoveSuccess = lib.removeUser(user->getUserId());
    assert(userRemoveSuccess == false); 
    std::cout << "✓ Prevented removal of user with borrowed books\n";
    
    std::cout << "\nAll tests passed successfully!n";
}

int main() {
    runAllTests();
    return 0;
}