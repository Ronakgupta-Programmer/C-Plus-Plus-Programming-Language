#include <iostream>
#include <cmath>
using namespace std;

bool isArmstrong(int num);

int main() {
    int number;

    cout << "--- Armstrong Number Checker ---" << endl;
    cout << "Enter an integer: ";
    cin >> number;

    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int originalNumber, remainder, n = 0;
    double result = 0.0;

    originalNumber = num;

    // Count the number of digits
    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = num;

    // Calculate the sum of the digits raised to the power of n
    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }

    // Check if the sum is equal to the original number
    return (int)result == num;
}
