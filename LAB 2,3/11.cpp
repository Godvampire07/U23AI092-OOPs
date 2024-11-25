#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Period {
    string subject, teacher;
};

int main() {
    srand(time(0));

    Period periods[] = {
        {"Math", "Mr. A"}, {"English", "Ms. B"}, {"Science", "Dr. C"}, {"History", "Ms. D"}
    };

    int randomIndex = rand() % 4;
    cout << "Today's Class Period:\nSubject: " << periods[randomIndex].subject << ", Teacher: " << periods[randomIndex].teacher << endl;

    return 0;
}
