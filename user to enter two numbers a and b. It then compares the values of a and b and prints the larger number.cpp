#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int a, b;
    
    cout << "Enter a: ";
    cin >> a;
    
    cout << "Enter b: ";
    cin >> b;
    
    if (a > b)
        cout << endl << a;
    else if (b > a)
        cout << endl << b;
    else
        cout << endl << "Both numbers are equal.";
    
    return 0;
}