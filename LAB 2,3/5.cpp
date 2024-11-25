#include <iostream>
using namespace std;

struct Fraction {
    int numerator, denominator;
};

Fraction add(Fraction f1, Fraction f2) { // Call-by-value
    Fraction result;
    result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
    return result;
}

void subtract(const Fraction &f1, const Fraction &f2, Fraction &result) { // Call-by-reference
    result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    result.denominator = f1.denominator * f2.denominator;
}

void multiply(Fraction *f1, Fraction *f2, Fraction *result) { // Call-by-address
    result->numerator = f1->numerator * f2->numerator;
    result->denominator = f1->denominator * f2->denominator;
}

int main() {
    Fraction f1 = {3, 4}, f2 = {2, 5}, result;

    cout << "Adding fractions:\n";
    result = add(f1, f2);
    cout << result.numerator << "/" << result.denominator << endl;

    cout << "\nSubtracting fractions:\n";
    subtract(f1, f2, result);
    cout << result.numerator << "/" << result.denominator << endl;

    cout << "\nMultiplying fractions:\n";
    multiply(&f1, &f2, &result);
    cout << result.numerator << "/" << result.denominator << endl;

    return 0;
}
