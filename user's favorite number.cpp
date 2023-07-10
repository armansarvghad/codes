#include <iostream>

int main() {
    int currentNumber = 0;
    int sum = 0;
    int count = 0;

    while (currentNumber == 0) {
        std::cout << "Enter your favorite number: ";
        std::cin >> currentNumber;

        count++;

        if (currentNumber != 0) {
            sum += currentNumber;
        }

        if (count < currentNumber) {
            std::cout << sum << " + ";
        } 
        else 
        {
            std::cout << sum;
        }
    }

    std::cout << " = " << sum << std::endl;

    return 0;
}