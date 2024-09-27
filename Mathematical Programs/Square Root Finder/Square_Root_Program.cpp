#include <iostream>
#include <cmath> // Include cmath for sqrt()

int main() {
    double number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Square root is not defined for negative numbers." << std::endl;
    } else {
        double result = sqrt(number);
        std::cout << "The square root of " << number << " is " << result << std::endl;
    }

    return 0;
}
