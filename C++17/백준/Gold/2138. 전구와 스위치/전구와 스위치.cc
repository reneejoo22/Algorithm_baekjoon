// 2036
#include <iostream>
#include <vector>
using namespace std;

int n;
string str1, str2;
int ans = -1;

char change(char c) {
	if (c == '0') {
		return '1';
	}
	else 
		return '0';
}

void solve(string& s, int idx, int cnt) {

	if (idx == n) {  // 끝까지 돌면
		if (s[idx - 1] == str2[idx - 1]) {
			if (ans == -1) {
				ans = cnt;
			}
			else {
				ans = min(ans, cnt);
			}
		}
		return;
	}

	if (s[idx - 1] == str2[idx - 1]) {  // 같으면
		solve(s, idx + 1, cnt);
	}
	else if (s[idx - 1] != str2[idx - 1]) {
		s[idx] = change(s[idx]);
		s[idx - 1] = change(s[idx - 1]);

		if (s[idx + 1] != n) {
			s[idx + 1] = change(s[idx + 1]);
		}

		solve(s, idx + 1, cnt + 1);
	}

	return;

}


int main() {

	cin >> n;  //3
	cin >> str1 >> str2;

	string tmp = str1;

	solve(str1, 1, 0);   //탐색할 위치, 누른 횟수

	if (ans == -1) {
		str1 = tmp;
		str1[0] = change(str1[0]);
		str1[1] = change(str1[1]);
		solve(str1, 1, 1);
	}

	cout << ans;
}