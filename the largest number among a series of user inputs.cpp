#include <iostream>
using namespace std;

int main() {
    int max = 0;
    int n;

    cout << "Enter the number of numbers you want: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;
        cout << "Enter number " << i << ": ";
        cin >> x;

        if (x > max) {
            max = x;
        }
    }

    cout << "The largest number you have entered: " << max << endl;

    return 0;
}