//1213
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int at[26] = { 0 };

int main() {
	string name;
	cin >> name;

	for (int i = 0;i < name.size();i++) {
		at[name[i] - 'A']++;
	}

	int cnt = 0, mid = -1;
	for (int p = 0;p < 26;p++) {
		if (at[p] != 0) {
			if (at[p] % 2 != 0) {
				cnt++;
				mid = p;
			}
		}
		if (cnt > 1) {
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}

	string ans = "", tmp = "";
	for (int q = 0;q < 26;q++) {
		if (at[q] > 0) {
			for (int z = 0;z < at[q]/2; z++) {
				ans += q + 'A';
			}
		}
	}
	
	tmp = ans;
	reverse(tmp.begin(), tmp.end());

	if (mid != -1) {
		ans += mid + 'A';
	}

	ans += tmp;
	cout << ans;
}