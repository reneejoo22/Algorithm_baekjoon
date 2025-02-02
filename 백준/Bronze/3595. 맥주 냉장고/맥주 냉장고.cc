#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int main() {
    fastio;

    int n;
    cin >> n;

    long min = 100000001;
    
    int num[3];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i * j > n) break;
            for (int k = 1; k <= j; k++) {
                if (i * j * k > n) break;
                if (i * j * k == n) {
                    long sum = i * j + j * k + k * i;
                    if (sum < min) {
                        min = sum;
                        num[0] = i;
                        num[1] = j;
                        num[2] = k;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= 2; i++) cout << num[i] << " ";
}