// 1082
#include <iostream>
#include <vector>
using namespace std;

int price[10];
int n, m;
int r[51]; // 만들 수
int minPrice = 100;  // 0을 제외한 가장 작은 수
int minPrice2 = 100;  // 0을 포함한 가장 작은 수
int minIdx, minIdx2;
int idx;

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
        if (i > 0 && price[i] <= minPrice) {
            minPrice = price[i];
            minIdx = i;
        }
        if (price[i] <= minPrice2) {
            minPrice2 = price[i];
            minIdx2 = i;
        }
    }

    cin >> m;
    if (m < minPrice) {
        cout << 0;
        return 0;
    }
    // 일단 살 수 있으면 하나 사고
    r[0] = minIdx;
    m -= minPrice;
    idx++;

    while (m >= minPrice2) {
        m -= minPrice2;
        r[idx] = minIdx2;
        idx++;
    }
    for (int i = 0;i < idx;i++) {
        for (int j = n - 1; j > r[i]; j--) {
            if (m + price[r[i]] - price[j] >= 0) {
                m += price[r[i]];
                m -= price[j];
                r[i] = j;
                break;
            }
        }
    }

    for (int i = 0;i < idx;i++) {
        cout << r[i];
    }
}
