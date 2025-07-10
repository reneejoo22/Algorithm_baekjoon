#include <iostream>
#include <set>
using namespace std;

int N;
set<int> st;

int ans = 5;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int x; cin >> x;
		st.insert(x);
	}

	for (auto& x : st) {
		int cnt = 4;
		for (int i = 1; i < 5; i++) {
			if (st.count(x + i)) cnt--;
		}
		ans = min(ans, cnt);
	}

	cout << ans;
}