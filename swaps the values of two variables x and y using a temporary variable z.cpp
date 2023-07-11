#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int x, y;
    cout << "Enter first number: ";
    cin >> x;
    
    cout << "Enter second number: ";
    cin >> y;
    
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    
    cout << endl << x << "," << y;
    
    return 0;
}