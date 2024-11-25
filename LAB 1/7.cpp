#include <iostream>
using namespace std;

struct Arithmetic {
    int no1, no2;
};

void add(Arithmetic a) {
    cout << "Addition: " << a.no1 + a.no2 << endl;
}

void sub(Arithmetic a) {
    cout << "Subtraction: " << a.no1 - a.no2 << endl;
}

void mul(Arithmetic a) {
    cout << "Multiplication: " << a.no1 * a.no2 << endl;
}

void div(Arithmetic a) {
    if (a.no2 != 0)
        cout << "Division: " << static_cast<double>(a.no1) / a.no2 << endl;
    else
        cout << "Division by zero is not allowed!" << endl;
}

int main() {
    Arithmetic a;
    int choice;

    cout << "Enter two numbers: ";
    cin >> a.no1 >> a.no2;

    do {
        cout << "\nChoose an operation:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add(a);
                break;
            case 2:
                sub(a);
                break;
            case 3:
                mul(a);
                break;
            case 4:
                div(a);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
