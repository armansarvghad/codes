#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int x, n;

    cout << "Enter the number of numbers: ";
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        cout << "Enter a number: ";
        cin >> n;

        if (n % 10 == 5)
            cout << "Yes" << endl;
    }

    return 0;
}