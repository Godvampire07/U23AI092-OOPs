#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title, author;
    int copies;
};

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\nLibrary Menu:\n1. Add Book\n2. Display Books\n3. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Book book;
            cout << "Enter title, author, and number of copies: ";
            cin >> book.title >> book.author >> book.copies;
            library.push_back(book);
        } else if (choice == 2) {
            cout << "Books in Library:\n";
            for (auto &book : library) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", Copies: " << book.copies << endl;
            }
        }
    } while (choice != 3);

    return 0;
}
