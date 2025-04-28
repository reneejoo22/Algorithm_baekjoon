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

        if (cur < v[i].first) {   // 0   < 1  .... 7 < 8.... 14 <13!!
            tmp = (v[i].second - v[i].first) / l;  // 1 .... 3

            if ((v[i].second - v[i].first) % l != 0) {
                tmp++;     // 2... 4
            }

            cur = v[i].first + tmp * l;  // 7... 8
            ans += tmp;
        }

        
        else if (cur < v[i].second) {
            tmp = (v[i].second - cur) / l;  // (17 - 14)/3 = 1

            if ((v[i].second - cur) % l != 0) {
                tmp++;     // 2... 4
            }

            cur = cur + tmp * l;  // 14 + 1*3 = 17
            ans += tmp;
        }

        /*cout << "cur_" << cur << endl;*/
    }

    cout << ans;
}