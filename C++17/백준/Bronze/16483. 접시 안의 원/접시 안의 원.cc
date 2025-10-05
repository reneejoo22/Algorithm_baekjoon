#include <iostream>
using namespace std;

int main()
{
    int T;

    cin >> T;

    double res = T / 2.0;

    cout << (int)(res * res + 0.5) << '\n';

    return 0;
}