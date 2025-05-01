// 1689
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>>v;  //오름차순
    for (int i = 0;i < n;i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({ s,1 });
        v.push_back({ e,-1 });
    }
    sort(v.begin(), v.end());  //오름

    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        cnt += v[i].second;  //  1  2  1  2  1 0
        ans = max(cnt, ans);  // 1  2  2  2  2 2
    }

    cout << ans;
}