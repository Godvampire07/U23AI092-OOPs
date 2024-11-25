#include <iostream>
using namespace std;

class TelephoneBill {
    string name;
    int calls;
    double bill;

public:
    void getData() {
        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter number of calls: ";
        cin >> calls;
    }

    void computeBill() {
        if (calls <= 100)
            bill = 200;
        else if (calls <= 150)
            bill = 200 + (calls - 100) * 0.60;
        else if (calls <= 200)
            bill = 200 + (50 * 0.60) + (calls - 150) * 0.50;
        else
            bill = 200 + (50 * 0.60) + (50 * 0.50) + (calls - 200) * 0.40;
    }

    void display() {
        cout << "Customer Name: " << name << "\nBill Amount: Rs. " << bill << endl;
    }
};

int main() {
    TelephoneBill customer;
    customer.getData();
    customer.computeBill();
    customer.display();
    return 0;
}
