#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int x, n, sum = 0;

    cout << "Enter the total number of values: ";
    cin >> x;

    for (int i = 1; i <= x; i++)
    {
        cout << endl << "Enter value " << i << ": ";
        cin >> n;
        sum += n;
    }

    double average = static_cast<double>(sum) / x;

    cout << endl << "The average is: " << average;

    return 0;
}