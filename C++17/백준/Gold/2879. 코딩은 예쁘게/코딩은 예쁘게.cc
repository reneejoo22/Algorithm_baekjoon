// 2879
#include<iostream>
#include<vector>
using namespace std;

vector<int>tab;
vector<int>need_tab;

int main() {
	int n;
	cin >> n;

	tab.resize(n);
	for (int i = 0; i < n; i++) {
		int tab_num;
		cin >> tab_num;
		tab[i] = tab_num;
	}

	need_tab.resize(n);
	for (int i = 0; i < n; i++) {
		int need_tab_num;
		cin >> need_tab_num;

		//인접한 것끼리 묶는데 양수끼리 or 음수끼리
		need_tab[i] = need_tab_num - tab[i];
	}

	//n이 1인 경우도 고려해야함
	if (n == 1) {
		cout << abs(need_tab[0]) << endl;
	}
	else {
		int ans = 0;
		int pre = need_tab[0];
		int cur = need_tab[0];

		for (int i = 1; i < n; i++) {
			if (need_tab[i] >= 0) {
				if (pre < 0) {  //부호가 다르면
					ans += abs(pre);
					pre = need_tab[i];
				}
				else if (pre < need_tab[i]) {  //오름차순
					pre = need_tab[i];
				}
				else {  // 오름차순 끊기면
					ans += abs(pre) - abs(need_tab[i]);
					pre = cur = need_tab[i];
				}
			}
			else {
				if (pre > 0) {
					ans += pre;
					pre = need_tab[i];
				}
				else if (pre > need_tab[i]) {
					pre = need_tab[i];
				}
				else {
					ans += abs(pre) - abs(need_tab[i]);
					pre = cur = need_tab[i];
				}
			}
		}
		ans += abs(pre);
		cout << ans << endl;
	}
}
