#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

long long v[10001];
long long gap[10001];

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    for (int i = 1;i <= n;i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);  // 오름


    for (int i = 1; i < n; i++) {
        gap[i] = v[i+1] - v[i];
        //cout << gap[i]<<endl;
    }
    sort(gap + 1, gap + n, greater<>()); // 내림_ 시작이 큰 수_greater


    int ans = 0;
    for (int i = k;i < n;i++) { // 10 ... 5
        ans += gap[i];
    }

    cout << ans;
    return 0;
}