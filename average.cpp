#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    double a, b, c;
    cout << "Enter A: ";
    cin >> a;

    cout << "Enter B: ";
    cin >> b;

    cout << "Enter C: ";
    cin >> c;

    double average = (a + b + c) / 3.0;

    cout << endl << "The average is: " << average;

    return 0;
}