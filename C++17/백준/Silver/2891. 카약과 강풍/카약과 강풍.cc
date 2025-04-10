// 2891
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

    int n, s, r;
    cin >> n >> s >> r;

    vector<int> team(n, 1);
    while (s--) { // 없는 팀 갱신
        int temp; cin >> temp;
        team[temp - 1]--;  // 없는 팀은 0
    }
    while (r--) { // 여분 팀 갱신
        int temp; cin >> temp;
        team[temp - 1]++;  // 여분 가져온 망가진 팀은 본인이 충족
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (team[i] > 1) { // 본인이 여분이 있을 때
            if (i - 1 > -1 && team[i - 1] < 1) {
                team[i - 1]++;
                team[i]--;
            }
            else if (i + 1 < n && team[i + 1] < 1) {
                team[i + 1]++;
                team[i]--;
            }
        }
    }
    for (auto now : team) {
        if (now == 0) ans++;
    }
    cout << ans<<endl;
}