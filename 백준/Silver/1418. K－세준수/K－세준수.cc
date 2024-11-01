#include <iostream>
using namespace std;
 
void k_sejun(int n, int k) {
    int div = 2;
    int count = 0;
 
    for (int i = 1; i <= n; i++) {
        int tmp = i;
        for (int j = 2; j <= k; j++) {
            while (tmp % j == 0) {
                tmp = tmp / j;
            }
        }
        if (tmp == 1) {
            count++;
        }
    }
    cout << count;
}
 
int main() {
    int n, k;
    cin >> n >> k;
    k_sejun(n, k);
}
