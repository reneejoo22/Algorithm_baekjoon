// 5014
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int>v(n);  //오름차순
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());  //오름

    int cnt = 0;
    while (1) {
        if (v.size() == 1) {
            break;
        }

        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        cnt++;
        v[0]--;

        if (v[0] == 0) {
            for (int i = 0;i < v.size() - 1;i++) {
                v[i] = v[i + 1];
            }
            v.pop_back();
        }

    }
    cout << cnt;
}
