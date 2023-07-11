#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int fact = 1, n;
    
    cout << "Enter your number: ";
    cin >> n;
    
    if (n < 0)
    {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1;
    }
    
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    
    cout << endl << "Factorial of " << n << " is: " << fact;
    
    return 0;
}