#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int num, r;
    bool stop = false;

    while (!stop)
    {
        cout << "Enter your number (enter 0 to stop): ";
        cin >> num;

        if (num == 0)
            stop = true;
        else
        {
            r = num % 2;
            if (r == 0)
                cout << "The number you entered is even." << endl;
            else
                cout << "The number you entered is odd." << endl;
        }
    }

    return 0;
}