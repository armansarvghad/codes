#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int a, d;
    
    cout << "Enter first number: ";
    cin >> a;
    
    cout << "Enter second number: ";
    cin >> d;
    
    if (a % d == 0)
        cout << endl << "Yes";
    else
        cout << endl << "No";
    
    return 0;
}