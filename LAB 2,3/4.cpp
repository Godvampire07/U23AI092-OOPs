#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int admno;
    char name[20];
    float marksEng, marksMaths, marksSci, total;

    inline void compute() {
        total = marksEng + marksMaths + marksSci;
    }

public:
    // Default constructor
    Student() : admno(0), marksEng(0), marksMaths(0), marksSci(0), total(0) {
        strcpy(name, "Unknown");
    }

    void readData(int adm = 0, const char *n = "Default", float eng = 0.0, float maths = 0.0, float sci = 0.0) {
        admno = adm;
        strcpy(name, n);
        marksEng = eng;
        marksMaths = maths;
        marksSci = sci;
        compute();
    }

    void showData() const {
        cout << "Admission No.: " << admno << endl;
        cout << "Name: " << name << endl;
        cout << "Marks - English: " << marksEng << ", Maths: " << marksMaths << ", Science: " << marksSci << endl;
        cout << "Total Marks: " << total << endl;
    }
};

int main() {
    Student s1;
    s1.readData(1, "Alice", 85.5, 90.0, 78.5);

    cout << "Student Details:\n";
    s1.showData();

    return 0;
}
