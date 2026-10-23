#include <iostream>

// function prototypes (declared before main)
void addNumbers(double num1, double num2);
bool isGreater(double A, double B);
bool checkLogicalOps(bool x, bool y);

int main() {
    // driver code - calling each function

    // 1. sum of two numbers
    addNumbers(5, 10);

    // 2. check if A is greater than B
    double A = 15, B = 8;
    if (isGreater(A, B)) {
        std::cout << A << " is greater than " << B << std::endl;
    } else {
        std::cout << A << " is NOT greater than " << B << std::endl;
    }

    // 3. logical operations
    bool x = true, y = false;
    if (checkLogicalOps(x, y)) {
        std::cout << "Logical operations successful!" << std::endl;
    }

    return 0;
}

// function definitions (after main)
void addNumbers(double num1, double num2) {
    double sum = num1 + num2;
    std::cout << "Sum: " << sum << std::endl;
}

bool isGreater(double A, double B) {
    return A > B;
}

bool checkLogicalOps(bool x, bool y) {
    std::cout << "\n--- Logical Operations ---" << std::endl;
    std::cout << "x AND y = " << (x && y) << std::endl;
    std::cout << "x OR y  = " << (x || y) << std::endl;
    std::cout << "NOT x   = " << (!x) << std::endl;
    return true;  // success
}