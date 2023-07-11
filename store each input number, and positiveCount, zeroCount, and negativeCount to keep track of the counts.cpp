#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int m, num, positiveCount = 0, zeroCount = 0, negativeCount = 0;

    cout << "Enter the number of numbers: ";
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cout << endl << "Enter the number: ";
        cin >> num;

        if (num > 0)
            positiveCount++;
        else if (num < 0)
            negativeCount++;
        else
            zeroCount++;
    }

    cout << endl << "Number of positive numbers: " << positiveCount;
    cout << endl << "Number of zero numbers: " << zeroCount;
    cout << endl << "Number of negative numbers: " << negativeCount;

    return 0;
}