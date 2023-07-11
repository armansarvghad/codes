#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter your number: ";
    cin >> num;

    int sum = 0;
    int temp = num;

    while (temp != 0) {
        int digit = temp % 10;
        sum += digit;
        temp /= 10;
    }

    cout << "The sum of the individual digits: " << sum << endl;

    return 0;
}