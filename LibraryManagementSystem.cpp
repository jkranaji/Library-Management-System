#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Class to represent a book
class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int id, string title, string author) : id(id), title(title), author(author), issued(false) {}
};

// Class to represent the library
class Library
{
private:
    vector<Book> books;
    unordered_map<int, int> bookIndex; // Maps book ID to index in the books vector

public:
    // Function to add a new book to the library
    void addBook(int id, string title, string author)
    {
        if (bookIndex.find(id) == bookIndex.end())
        {
            books.push_back(Book(id, title, author));
            bookIndex[id] = books.size() - 1;
            cout << "Book added successfully!" << endl;
        }
        else
        {
            cout << "Book ID already exists!" << endl;
        }
    }

    // Function to display all books in the library
    void displayBooks()
    {
        cout << "Books in the library:" << endl;
        for (const auto &book : books)
        {
            cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author;
            if (book.issued)
            {
                cout << " [Issued]";
            }
            cout << endl;
        }
    }

    // Function to issue a book
    void issueBook(int id)
    {
        if (bookIndex.find(id) != bookIndex.end())
        {
            int index = bookIndex[id];
            if (!books[index].issued)
            {
                books[index].issued = true;
                cout << "Book issued successfully!" << endl;
            }
            else
            {
                cout << "Book is already issued!" << endl;
            }
        }
        else
        {
            cout << "Book ID not found!" << endl;
        }
    }

    // Function to return a book
    void returnBook(int id)
    {
        if (bookIndex.find(id) != bookIndex.end())
        {
            int index = bookIndex[id];
            if (books[index].issued)
            {
                books[index].issued = false;
                cout << "Book returned successfully!" << endl;
            }
            else
            {
                cout << "Book was not issued!" << endl;
            }
        }
        else
        {
            cout << "Book ID not found!" << endl;
        }
    }
};

// Main function
int main()
{
    Library library;
    int choice, id;
    string title, author;

    while (true)
    {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            library.displayBooks();
            break;
        case 3:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            library.issueBook(id);
            break;
        case 4:
            cout << "Enter Book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;
        case 5:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
