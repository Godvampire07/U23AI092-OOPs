#include <iostream>
using namespace std;

class Library {
private:
    static const int daysInMonth[12];
    int day, month, year;

    inline void incrementDay(int &day, int &month, int &year, int days) const {
        day += days;
        while (day > daysInMonth[month - 1]) {
            day -= daysInMonth[month - 1];
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

public:
    Library(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    void calculateDueDate(int daysToDue) const {
        int dueDay = day, dueMonth = month, dueYear = year;
        incrementDay(dueDay, dueMonth, dueYear, daysToDue);
        cout << "Due date: " << dueDay << "-" << dueMonth << "-" << dueYear << endl;
    }

    void display() const {
        cout << "Issue Date: " << day << "-" << month << "-" << year << endl;
    }
};

const int Library::daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int day, month, year, daysToDue;

    cout << "Enter the issue date (day month year): ";
    cin >> day >> month >> year;
    cout << "Enter the number of days to due: ";
    cin >> daysToDue;

    Library book(day, month, year);
    book.display();
    book.calculateDueDate(daysToDue);

    return 0;
}
