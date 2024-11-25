#include <iostream>
using namespace std;

struct Complex {
    int real, imag;
};

Complex add(Complex a, Complex b) {
    return {a.real + b.real, a.imag + b.imag};
}

Complex sub(Complex a, Complex b) {
    return {a.real - b.real, a.imag - b.imag};
}

Complex mul(Complex a, Complex b) {
    return {a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real};
}

Complex div(Complex a, Complex b) {
    int denominator = b.real * b.real + b.imag * b.imag;
    return {(a.real * b.real + a.imag * b.imag) / denominator, (a.imag * b.real - a.real * b.imag) / denominator};
}

void menu() {
    cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
}

int main() {
    Complex a, b, result;
    int choice;
    cout << "Enter first complex number (real and imaginary): ";
    cin >> a.real >> a.imag;
    cout << "Enter second complex number (real and imaginary): ";
    cin >> b.real >> b.imag;

    menu();
    cout << "Choose an operation: ";
    cin >> choice;

    switch (choice) {
        case 1:
            result = add(a, b);
            break;
        case 2:
            result = sub(a, b);
            break;
        case 3:
            result = mul(a, b);
            break;
        case 4:
            result = div(a, b);
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    cout << "Result: " << result.real << " + " << result.imag << "i" << endl;
    return 0;
}
