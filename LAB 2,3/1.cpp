#include <iostream>
using namespace std;

class Order {
private:
    static const double minerCost;
    static const double toasterCost;
    static const double fanCost;

    static const double minerDiscount;
    static const double toasterDiscount;
    static const double fanDiscount;

    static const double salesTax;

public:
    inline double calculateNetPrice(int quantity, double cost, double discount) const {
        return quantity * cost * (1 - discount);
    }

    inline double calculateTax(double netPrice) const {
        return netPrice * salesTax;
    }

    void calculateAmount(int miners = 0, int toasters = 0, int fans = 0) const {
        double netMiner = calculateNetPrice(miners, minerCost, minerDiscount);
        double netToaster = calculateNetPrice(toasters, toasterCost, toasterDiscount);
        double netFan = calculateNetPrice(fans, fanCost, fanDiscount);

        double totalNetPrice = netMiner + netToaster + netFan;
        double tax = calculateTax(totalNetPrice);
        double totalAmount = totalNetPrice + tax;

        cout << "Total Amount to be paid: Rs. " << totalAmount << endl;
    }
};

const double Order::minerCost = 1500.0;
const double Order::toasterCost = 200.0;
const double Order::fanCost = 450.0;

const double Order::minerDiscount = 0.05;
const double Order::toasterDiscount = 0.10;
const double Order::fanDiscount = 0.15;

const double Order::salesTax = 0.10;

int main() {
    Order storeOrder;
    int miners, toasters, fans;

    cout << "Enter the number of miners, toasters, and fans: ";
    cin >> miners >> toasters >> fans;

    storeOrder.calculateAmount(miners, toasters, fans);
    return 0;
}
