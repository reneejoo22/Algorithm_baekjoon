#include <iostream>
using namespace std;
int main() {
    int t, candy, bs;
    cin >> t;
    while (t--)
    {
        cin >> candy >> bs;
        cout << "You get " << candy / bs << " piece(s) and your dad gets "<< candy%bs << " piece(s)."<<'\n';
    }
}