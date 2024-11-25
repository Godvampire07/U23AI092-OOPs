#include <iostream>
using namespace std;

int main() {
    int miners, toasters, fans;
    double total, salesTax, discount;

    cout << "Enter the number of miners, toasters, and fans: ";
    cin >> miners >> toasters >> fans;

    double minersCost = miners * 1500;
    double toastersCost = toasters * 200;
    double fansCost = fans * 450;

    double minersDiscount = minersCost * 0.05;
    double toastersDiscount = toastersCost * 0.10;
    double fansDiscount = fansCost * 0.15;

    total = minersCost + toastersCost + fansCost - (minersDiscount + toastersDiscount + fansDiscount);
    salesTax = total * 0.10;
    total += salesTax;

    cout << "The total amount to be paid: Rs. " << total << endl;
    return 0;
}
