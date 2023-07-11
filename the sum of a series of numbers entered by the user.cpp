#include <iostream>
using namespace std;

int main()
{
    int totalNumbers;
    cout << "Enter the total number of numbers you want to sum: ";
    cin >> totalNumbers;

    int sum = 0;
    for (int i = 0; i < totalNumbers; i++)
    {
        int number;
        cout << "Enter number " << (i + 1) << ": ";
        cin >> number;
        sum += number;
    }

    cout << "The sum of the numbers you entered: " << sum << endl;

    return 0;
}