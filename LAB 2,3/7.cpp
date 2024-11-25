#include <iostream>
using namespace std;

class Array {
    int *arr, size;

public:
    Array(int s) {
        size = s;
        arr = new int[size];
        cout << "Enter " << size << " elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    ~Array() {
        delete[] arr;
    }

    int findLargest() {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) max = arr[i];
        }
        return max;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    Array a(n);
    cout << "Largest element: " << a.findLargest() << endl;

    return 0;
}
