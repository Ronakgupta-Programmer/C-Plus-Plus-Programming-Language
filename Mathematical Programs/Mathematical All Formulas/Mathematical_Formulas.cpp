#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

// Function to calculate Fibonacci sequence
void fibonacci(int n, int* fib_sequence) {
    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        exit(1);
    }
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;
    for (int i = 2; i < n; i++) {
        fib_sequence[i] = fib_sequence[i-1] + fib_sequence[i-2];
    }
}

// Function to calculate factorial
int factorial(int n) {
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        exit(1);
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Basic arithmetic operations
float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    if (b == 0) {
        cout << "Cannot divide by zero." << endl;
        exit(1);
    }
    return a / b;
}

float modulus(float a, float b) {
    return fmod(a, b);
}

float exponentiate(float base, float exp) {
    return pow(base, exp);
}

float square_root(float n) {
    if (n < 0) {
        cout << "Square root is not defined for negative numbers." << endl;
        exit(1);
    }
    return sqrt(n);
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

float logarithm(float base, float value) {
    if (base <= 0 || base == 1 || value <= 0) {
        cout << "Logarithm is undefined for this input." << endl;
        exit(1);
    }
    return log(value) / log(base);
}

int is_power_of_two(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

float mean(float* numbers, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum / size;
}

float geometric_mean(float* numbers, int size) {
    float product = 1.0;
    for (int i = 0; i < size; i++) {
        product *= numbers[i];
    }
    return pow(product, 1.0 / size);
}

float median(float* numbers, int size) {
    float sorted_numbers[size];
    memcpy(sorted_numbers, numbers, size * sizeof(float));
    qsort(sorted_numbers, size, sizeof(float), compare_floats);
    int mid = size / 2;
    if (size % 2 == 0) {
        return (sorted_numbers[mid - 1] + sorted_numbers[mid]) / 2.0;
    }
    return sorted_numbers[mid];
}

int compare_floats(const void* a, const void* b) {
    float fa = *(float*)a;
    float fb = *(float*)b;
    if (fa < fb) return -1;
    if (fa > fb) return 1;
    return 0;
}

float mode(float* numbers, int size) {
    int counts[size];
    memset(counts, 0, size * sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                counts[i]++;
            }
        }
    }
    int max_count = 0;
    int max_index = 0;
    for (int i = 0; i < size; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
            max_index = i;
        }
    }
    return numbers[max_index];
}

float variance(float* numbers, int size) {
    float avg = mean(numbers, size);
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += pow(numbers[i] - avg, 2);
    }
    return sum / size;
}

float standard_deviation(float* numbers, int size) {
    return sqrt(variance(numbers, size));
}

float compound_interest(float principal, float rate, float time, int frequency) {
    return principal * pow(1 + rate / frequency, frequency * time);
}

float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

float area_circle(float radius) {
    return M_PI * radius * radius;
}

float perimeter_circle(float radius) {
    return 2 * M_PI * radius;
}

float area_triangle(float base, float height) {
    return 0.5 * base * height;
}

float area_trapezoid(float base1, float base2, float height) {
    return 0.5 * (base1 + base2) * height;
}

void matrix_addition(float* matrix_a, float* matrix_b, float* result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i * cols + j] = matrix_a[i * cols + j] + matrix_b[i * cols + j];
        }
    }
}

void matrix_multiplication(float* matrix_a, float* matrix_b, float* result, int rows_a, int cols_a, int cols_b) {
    for (int i = 0; i < rows_a; i++) {
        for (int j = 0; j < cols_b; j++) {
            for (int k = 0; k < cols_a; k++) {
                result[i * cols_b + j] += matrix_a[i * cols_a + k] * matrix_b[k * cols_b + j];
            }
        }
    }
}

void quadratic_solver(float a, float b, float c, float* roots) {
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        cout << "No real roots." << endl;
    } else if (discriminant == 0) {
        roots[0] = -b / (2 * a);
    } else {
        roots[0] = (-b + sqrt(discriminant)) / (2 * a);
        roots[1] = (-b - sqrt(discriminant)) / (2 * a);
    }
}

float pendulum_period(float length) {
    return 2 * M_PI * sqrt(length / 9.81);
}

int permutations(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int combinations(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

float pythagorean_theorem(float a, float b) {
    return sqrt(a * a + b * b);
}

float surface_area_cylinder(float radius, float height) {
    return 2 * M_PI * radius * (radius + height);
}

float volume_cylinder(float radius, float height) {
    return M_PI * radius * radius * height;
}

int main() {
    int choice;
    cout << "Choose an operation:" << endl;
    cout << "1. Fibonacci" << endl;
    cout << "2. Factorial" << endl;
    cout << "3. Addition" << endl;
    cout << "4. Subtraction" << endl;
    cout << "5. Multiplication" << endl;
    cout << "6. Division" << endl;
    cout << "7. Modulus" << endl;
    cout << "8. Exponentiation" << endl;
    cout << "9. Square Root" << endl;
    cout << "10. Check Prime" << endl;
    cout << "11. GCD" << endl;
    cout << "12. LCM" << endl;
    cout << "13. Logarithm" << endl;
    cout << "14. Check Power of Two" << endl;
    cout << "15. Mean" << endl;
    cout << "16. Geometric Mean" << endl;
    cout << "17. Median" << endl;
    cout << "18. Mode" << endl;
    cout << "19. Variance" << endl;
    cout << "20. Standard Deviation" << endl;
    cout << "21. Compound Interest" << endl;
    cout << "22. Area and Perimeter of Rectangle" << endl;
    cout << "23. Area and Circumference of Circle" << endl;
    cout << "24. Area of Triangle" << endl;
    cout << "25. Area of Trapezoid" << endl;
    cout << "26. Matrix Addition" << endl;
    cout << "27. Matrix Multiplication" << endl;
    cout << "28. Quadratic Equation Solver" << endl;
    cout << "29. Pendulum Period" << endl;
    cout << "30. Permutations" << endl;
    cout << "31. Combinations" << endl;
    cout << "32. Pythagorean Theorem" << endl;
    cout << "33. Surface Area and Volume of Cylinder" << endl;
    
    cin >> choice;
    
    if (choice == 1) {
        int n;
        cout << "Enter the number of Fibonacci terms: ";
        cin >> n;
        int fib_sequence[n];
        fibonacci(n, fib_sequence);
        cout << "Fibonacci sequence: ";
        for (int i = 0; i < n; i++) {
            cout << fib_sequence[i] << " ";
        }
        cout << endl;
    } else if (choice == 2) {
        int n;
        cout << "Enter a number to compute factorial: ";
        cin >> n;
        int result = factorial(n);
        cout << "Factorial of " << n << ": " << result << endl;
    } else if (choice == 3) {
        float a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "Sum: " << add(a, b) << endl;
    } else if (choice == 4) {
        float a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "Difference: " << subtract(a, b) << endl;
    } else if (choice == 5) {
        float a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "Product: " << multiply(a, b) << endl;
    } else if (choice == 6) {
        float a, b;
        cout << "Enter numerator: ";
        cin >> a;
        cout << "Enter denominator: ";
        cin >> b;
        float result = divide(a, b);
        cout << "Quotient: " << result << endl;
    } else if (choice == 7) {
        float a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b ;
        cout << a << " % " << b << " = " << modulus(a, b) << endl;
    } else if (choice == 8) {
        float base, exp;
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter exponent: ";
        cin >> exp;
        cout << base << " raised to the power of " << exp << " is: " << exponentiate(base, exp) << endl;
    } else if (choice == 9) {
        float n;
        cout << "Enter a number to compute square root: ";
        cin >> n;
        float result = square_root(n);
        cout << "Square root of " << n << " is: " << result << endl;
    } else if (choice == 10) {
        int n;
        cout << "Enter a number to check if it is prime: ";
        cin >> n;
        if (is_prime(n)) {
            cout << n << " is a prime number." << endl;
        } else {
            cout << n << " is not a prime number." << endl;
        }
    } else if (choice == 11) {
        int a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    } else if (choice == 12) {
        int a, b;
        cout << "Enter first number: ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;
        cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;
    } else if (choice == 13) {
        float base, value;
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter value: ";
        cin >> value;
        float result = logarithm(base, value);
        cout << "Logarithm of " << value << " with base " << base << " is: " << result << endl;
    } else if (choice == 14) {
        int n;
        cout << "Enter a number to check if it is a power of two: ";
        cin >> n;
        if (is_power_of_two(n)) {
            cout << n << " is a power of two." << endl;
        } else {
            cout << n << " is not a power of two." << endl;
        }
    } else if (choice == 15) {
        int size;
        cout << "Enter the number of numbers: ";
        cin >> size;
        float numbers[size];
        cout << "Enter numbers separated by spaces: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
        cout << "Mean: " << mean(numbers, size) << endl;
    } else if (choice == 16) {
        int size;
        cout << "Enter the number of numbers: ";
        cin >> size;
        float numbers[size];
        cout << "Enter numbers separated by spaces: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
        cout << "Geometric Mean: " << geometric_mean(numbers, size) << endl;
    } else if (choice == 17) {
        int size;
        cout << "Enter the number of numbers: ";
        cin >> size;
        float numbers[size];
        cout << "Enter numbers separated by spaces: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
        cout << "Median: " << median(numbers, size) << endl;
    } else if (choice == 18) {
        int size;
        cout << "Enter the number of numbers: ";
        cin >> size;
        float numbers[size];
        cout << "Enter numbers separated by spaces: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
        cout << "Mode: " << mode(numbers, size) << endl;
    } else if (choice == 19) {
        int size;
        cout << "Enter the number of numbers: ";
        cin >> size;
        float numbers[size];
        cout << "Enter numbers separated by spaces: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
        cout << "Variance: " << variance(numbers, size) << endl;
    } else if (choice == 20) {
        int size;
        cout << "Enter the number of numbers: ";
        cin >> size;
        float numbers [size];
        cout << "Enter numbers separated by spaces: ";
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }
        cout << "Standard Deviation: " << standard_deviation(numbers, size) << endl;
    } else if (choice == 21) {
        float principal, rate, time;
        int frequency;
        cout << "Enter principal amount: ";
        cin >> principal;
        cout << "Enter interest rate (in decimal): ";
        cin >> rate;
        cout << "Enter time (in years): ";
        cin >> time;
        cout << "Enter the number of times interest is compounded per year: ";
        cin >> frequency;
        cout << "Compound interest is: " << compound_interest(principal, rate, time, frequency) << endl;
    } else if (choice == 22) {
        float length, width;
        cout << "Enter length of the rectangle: ";
        cin >> length;
        cout << "Enter width of the rectangle: ";
        cin >> width;
        cout << "Area: " << area_rectangle(length, width) << endl;
        cout << "Perimeter: " << perimeter_rectangle(length, width) << endl;
    } else if (choice == 23) {
        float radius;
        cout << "Enter radius of the circle: ";
        cin >> radius;
        cout << "Area: " << area_circle(radius) << endl;
        cout << "Circumference: " << perimeter_circle(radius) << endl;
    } else if (choice == 24) {
        float base, height;
        cout << "Enter base of the triangle: ";
        cin >> base;
        cout << "Enter height of the triangle: ";
        cin >> height;
        cout << "Area: " << area_triangle(base, height) << endl;
    } else if (choice == 25) {
        float base1, base2, height;
        cout << "Enter base1 of the trapezoid: ";
        cin >> base1;
        cout << "Enter base2 of the trapezoid: ";
        cin >> base2;
        cout << "Enter height of the trapezoid: ";
        cin >> height;
        cout << "Area: " << area_trapezoid(base1, base2, height) << endl;
    } else if (choice == 26) {
        int rows;
        cout << "Enter number of rows for the matrices: ";
        cin >> rows;
        float matrix_a[rows * rows];
        float matrix_b[rows * rows];
        float result[rows * rows];
        cout << "Enter the first matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                cin >> matrix_a[i * rows + j];
            }
        }
        cout << "Enter the second matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                cin >> matrix_b[i * rows + j];
            }
        }
        matrix_addition(matrix_a, matrix_b, result, rows, rows);
        cout << "Result of addition:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < rows; j++) {
                cout << result[i * rows + j] << " ";
            }
            cout << endl;
        }
    } else if (choice == 27) {
        int rows_a, cols_a, rows_b, cols_b;
        cout << "Enter number of rows for first matrix: ";
        cin >> rows_a;
        cout << "Enter number of columns for first matrix: ";
        cin >> cols_a;
        cout << "Enter number of rows for second matrix: ";
        cin >> rows_b;
        cout << "Enter number of columns for second matrix: ";
        cin >> cols_b;
        if (cols_a != rows_b) {
            cout << "Matrix multiplication is not possible." << endl;
        } else {
            float matrix_a[rows_a * cols_a];
            float matrix_b[rows_b * cols_b];
            float result[rows_a * cols_b];
            cout << "Enter the first matrix:" << endl;
            for (int i = 0; i < rows_a; i++) {
                for (int j = 0; j < cols_a; j++) {
                    cin >> matrix_a[i * cols_a + j];
                }
            }
            cout << "Enter the second matrix:" << endl;
            for (int i = 0; i < rows_b; i++) {
                for (int j = 0; j < cols_b; j++) {
                    cin >> matrix_b[i * cols_b + j];
                }
            }
            matrix_multiplication(matrix_a, matrix_b, result, rows_a, cols_a, cols_b);
            cout << "Result of multiplication:" << endl;
            for (int i = 0; i < rows_a; i++) {
                for (int j = 0; j < cols_b; j++) {
                    cout << result[i * cols_b + j] << " ";
                }
                cout << endl;
            }
        }
    } else if (choice == 28) {
        float a, b, c ;
        cout << "Enter coefficient a: ";
        cin >> a;
        cout << "Enter coefficient b: ";
        cin >> b;
        cout << "Enter coefficient c: ";
        cin >> c;
        float roots[2];
        quadratic_solver(a, b, c, roots);
        cout << "Roots: " << roots[0] << " " << roots[1] << endl;
    } else if (choice == 29) {
        float length;
        cout << "Enter length of the pendulum (in meters): ";
        cin >> length;
        cout << "Period of the pendulum: " << pendulum_period(length) << " seconds" << endl;
    } else if (choice == 30) {
        int n, r;
        cout << "Enter total items (n): ";
        cin >> n;
        cout << "Enter selected items (r): ";
        cin >> r;
        cout << "Permutations: " << permutations(n, r) << endl;
    } else if (choice == 31) {
        int n, r;
        cout << "Enter total items (n): ";
        cin >> n;
        cout << "Enter selected items (r): ";
        cin >> r;
        cout << "Combinations: " << combinations(n, r) << endl;
    } else if (choice == 32) {
        float a, b;
        cout << "Enter length of side a: ";
        cin >> a;
        cout << "Enter length of side b: ";
        cin >> b;
        cout << "Hypotenuse: " << pythagorean_theorem(a, b) << endl;
    } else if (choice == 33) {
        float radius, height;
        cout << "Enter radius of the cylinder: ";
        cin >> radius;
        cout << "Enter height of the cylinder: ";
        cin >> height;
        cout << "Surface Area: " << surface_area_cylinder(radius, height) << endl;
        cout << "Volume: " << volume_cylinder(radius, height) << endl;
    } else {
        cout << "Invalid choice. Please select a number between 1 and 33." << endl;
    }
    
    return 0;
}