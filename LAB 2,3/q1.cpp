#include <iostream>
#include <string>
#include <vector>
using namespace std;
class LineStorage {
private:
    vector<string> lines;

public:
    LineStorage() {
        cout << "Default constructor called.\n";
    }
    LineStorage(int n) {
        cout << "Parameterized constructor called.\n";
        string line;
        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            lines.push_back(line);
        }
    }
    LineStorage(LineStorage& other) {
        cout << "Copy constructor called.\n";
        lines = other.lines;
    }

    ~LineStorage() {
        cout << "Destructor called.\n";
    }
    void checkString(const std::string& str) const {
        int count = 0;
        for (auto&line : lines) {
            if (line == str) {
                ++count;
            }
        }

        if (count > 0) {
            cout << "The string is found " << count << " time(s) in the array.\n";
        } else {
            cout << "The stringis not found in the array.\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;
    cin.ignore();

    LineStorage ls(n);

    string searchString;
    cout << "Enter the string to search: ";
    getline(cin, searchString);

    ls.checkString(searchString);

    return 0;
}
