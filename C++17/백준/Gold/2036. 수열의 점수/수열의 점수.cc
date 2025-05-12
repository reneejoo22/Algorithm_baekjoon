// 2036
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;  //6

	vector<ll>m;
	vector<ll>p;
	int zero = 0, one = 0;
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;

		if (num == 0) {
			zero++;
		}
		else if (num == 1) {
			one++;
		}
		else if (num > 0) {
			p.push_back(num);
		}
		else {
			m.push_back(num);
		}
	} 

	sort(p.begin(), p.end(), greater<int>());  //내림차순
	sort(m.begin(), m.end());  // -8 -5 -3 -2 -1

	int pos_size = p.size();
	int neg_size = m.size();

	ll ans = 0;
	for (int i = 0;i < pos_size -1;i+=2) {  // 메모리 초과 발생할 수 있음
		ans += p[i] * p[i + 1];
	}
	if (pos_size % 2 != 0) {
		ans += p.back();
	}

	for (int i = 0;i < neg_size - 1;i += 2) {
		ans += m[i] * m[i + 1];
	}
	if (neg_size % 2 != 0 && !zero) {
		ans += m.back();
	}

	ans += one;

	cout << ans;
	return 0;
}