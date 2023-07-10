#include <iostream>
using namespace std;

int main()
{
    int totalNumbers;
    cout << "Enter the total number of numbers you want to input: ";
    cin >> totalNumbers;

    int divisibleBy2 = 0;
    int divisibleBy3 = 0;

    for (int i = 1; i <= totalNumbers; i++)
    {
        int number;
        cout << "Enter number " << i << ": ";
        cin >> number;

        if (number % 2 == 0)
        {
            divisibleBy2++;
        }

        if (number % 3 == 0)
        {
            divisibleBy3++;
        }
    }

    cout << "Numbers that are divisible by 2: " << divisibleBy2 << endl;
    cout << "Numbers that are divisible by 3: " << divisibleBy3 << endl;

    return 0;
}