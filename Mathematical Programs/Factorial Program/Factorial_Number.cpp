#include <iostream>
using namespace std;

unsigned long long factorial(int n);

int main() {
    int number;

    cout << "--- Factorial Finder ---" << endl;
    cout << "Enter a non-negative integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Error! Factorial of a negative number doesn't exist." << endl;
    } else {
        cout << "Factorial of " << number << " is " << factorial(number) << endl;
    }

    return 0;
}

// Recursive function to calculate factorial
unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}
