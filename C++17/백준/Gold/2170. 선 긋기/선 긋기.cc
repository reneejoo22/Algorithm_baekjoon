// 2170
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>>v(n);  //오름차순
    for (int i = 0;i < n;i++) {
        cin >> v[i].first>> v[i].second;
    }
    sort(v.begin(), v.end());  //오름

    long long ans = 0;
    long long s = v[0].first;
    long long e = v[0].second;
    if (n == 1) {
        cout << e - s;
        return 0;
    }

    for (int i = 1;i < n;i++) {
        if (e < v[i].first) {  // 안 겹침
            ans += e - s; 
            s = v[i].first;
            e = v[i].second;
        }
        else {   // 겹침
            if (e < v[i].second)
                e = v[i].second;
        }
    }
    
    ans += e - s;
    cout << ans;
}
