// 26099
#include <iostream>
#include <vector>
using namespace std;


int main() {
    long long n;
    cin >> n;
    
    long long ans = 0;
    while (n % 5) {
        n -= 3;
        ans++;
    }
    if (n < 0) {
        cout << -1;
    }
    else {
        cout << ans + n / 5;
    }
}
