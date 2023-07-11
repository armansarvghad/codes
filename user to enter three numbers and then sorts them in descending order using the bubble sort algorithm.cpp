#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;

    cout << "Enter the third number: ";
    cin >> c;

    if (a < b)
    {
        if (b < c)
            swap(a, c);
        else if (a < c)
            swap(a, b);
        else
        {
            int temp = a;
            a = c;
            c = b;
            b = temp;
        }
    }
    else
    {
        if (a < c)
            swap(a, c);
        else if (b < c)
        {
            int temp = a;
            a = b;
            b = c;
            c = temp;
        }
        else
            swap(b, c);
    }

    cout << endl << a << "," << b << "," << c;

    return 0;
}
