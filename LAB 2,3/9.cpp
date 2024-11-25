#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    double price;
};

int main() {
    int n;
    cout << "Enter the number of books: ";
    cin >> n;

    Book books[n], cheapest;
    cheapest.price = INT_MAX;

    for (int i = 0; i < n; i++) {
        cout << "Enter title and price for book " << i + 1 << ": ";
        cin >> books[i].title >> books[i].price;
        if (books[i].price < cheapest.price) {
            cheapest = books[i];
        }
    }

    cout << "\nCheapest Book: " << cheapest.title << " with price: Rs. " << cheapest.price << endl;
    return 0;
}
