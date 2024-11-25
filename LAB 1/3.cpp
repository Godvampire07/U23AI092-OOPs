#include <iostream>
#include <string>
using namespace std;

struct Publication {
    string title, author;
    double price;

    virtual void getData() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter author: ";
        cin >> author;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void display() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: Rs. " << price << endl;
    }
};

struct Book : public Publication {
    int count;

    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> count;
    }

    void display() override {
        Publication::display();
        cout << "Page Count: " << count << endl;
    }
};

struct Ebook : public Publication {
    double time;

    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in hours): ";
        cin >> time;
    }

    void display() override {
        Publication::display();
        cout << "Playing Time: " << time << " hours" << endl;
    }
};

int main() {
    Book book;
    Ebook ebook;

    cout << "Enter details for the book:\n";
    book.getData();

    cout << "\nEnter details for the ebook:\n";
    ebook.getData();

    cout << "\nDetails of the book:\n";
    book.display();

    cout << "\nDetails of the ebook:\n";
    ebook.display();

    return 0;
}
