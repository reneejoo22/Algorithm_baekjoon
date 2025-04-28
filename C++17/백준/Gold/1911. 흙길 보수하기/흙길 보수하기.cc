// 1911
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>>v(n);  //오름차순
    for (int i = 0;i < n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());  //오름

    int ans = 0, tmp;
    int cur = 0; // 널빤지 덮은 곳

    for (int i = 0; i < n; i++) {

        int start = max(cur, v[i].first);
        int len = v[i].second - start;

        if (len > 0) {
            int need = (len + l - 1) / l;  // len을 l로 나누되 올림(ceil)한 결과
            ans += need;
            cur = start + need * l;
        }

        /*cout << "cur_" << cur << endl;*/
    }

    cout << ans;
}