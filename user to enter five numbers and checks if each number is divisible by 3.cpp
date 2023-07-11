#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    const int numCount = 5;
    int numbers[numCount];

    for (int i = 0; i < numCount; i++)
    {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << endl << "Numbers divisible by 3: " << endl;

    for (int i = 0; i < numCount; i++)
    {
        if (numbers[i] % 3 == 0)
            cout << numbers[i] << endl;
    }

    return 0;
}