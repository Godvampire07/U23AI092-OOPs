#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNo;
    double balance;

public:
    BankAccount(string n, int acc, double bal) : name(n), accountNo(acc), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: Rs. " << amount << "\nNew Balance: Rs. " << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << "\nNew Balance: Rs. " << balance << endl;
        }
    }

    void display() const {
        cout << "Account Holder: " << name << "\nAccount Number: " << accountNo << "\nBalance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount account("John Doe", 123456, 10000.0);

    account.display();
    account.deposit(5000);
    account.withdraw(3000);
    account.withdraw(15000);

    return 0;
}
