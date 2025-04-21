// 20044
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int>v(n * 2);
    for (int i = 0; i < n*2; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int ans = 999999;
    for (int i = 0;i < n; i++) {
        /*cout << v[i] + v[n * 2 - i - 1] << endl;*/
        ans = min(ans, v[i] + v[n * 2 - i - 1]);
    }
    cout << ans;
}
