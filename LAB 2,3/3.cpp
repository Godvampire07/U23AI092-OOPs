#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

public:
    // Zero-argument constructor
    Date() : day(12), month(3), year(1993) {}

    // Parameterized constructor
    Date(int d = 12, int m = 10, int y = 2000) : day(d), month(m), year(y) {}

    // Copy constructor
    Date(const Date &obj) {
        day = obj.day;
        month = obj.month;
        year = obj.year;
    }

    // Function to display the date
    void display() const {
        cout << "Date: " << day << "-" << month << "-" << year << endl;
    }
};

int main() {
    Date date1=(15, 8, 2019); // Zero-argument constructor
    Date date2(15, 8, 2021); // Parameterized constructor
    Date date3(date2); // Copy constructor

    cout << "Default date:\n";
    date1.display();

    cout << "\nParameterized date:\n";
    date2.display();

    cout << "\nCopied date:\n";
    date3.display();

    return 0;
}
