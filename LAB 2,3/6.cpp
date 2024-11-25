#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    float marks;
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n], topper;
    topper.marks = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter name and marks for student " << i + 1 << ": ";
        cin >> students[i].name >> students[i].marks;
        if (students[i].marks > topper.marks) {
            topper = students[i];
        }
    }

    cout << "\nTopper: " << topper.name << " with marks: " << topper.marks << endl;
    return 0;
}
