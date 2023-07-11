#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
    int L, H, r, t, e;
    cout << "Enter the numbers for H, L: ";
    cin >> H >> L;
    
    if (L > H)
    {
        t = H;
        H = L;
        L = t;
    }
    
    for (e = L; e <= H; e += 2)
    {
        cout << endl << "The even numbers are: " << e;
    }
    
    return 0;
}