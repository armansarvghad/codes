#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int n, num, max = INT_MIN;

    cout << "Enter the number of numbers you want: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << endl << "Enter number " << i << ": ";
        cin >> num;

        if (num > max)
            max = num;
    }

    cout << endl << "The largest number you have entered: " << max;

    return 0;
}