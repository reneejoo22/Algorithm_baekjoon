#include<iostream>
using namespace std;

int main() {
    int a, b, c;
    int res = 0;
    cin >> a >> b >> c;

    if (a % b == 0) {

        cout << "0";
        return 0;
    }
    if (a > b)a = a % b;
    for (int i = 0; i < c; i++) {
        a *= 10;
        res = (int)(a / b);
        a = a % b;
    }
    cout << res;
}