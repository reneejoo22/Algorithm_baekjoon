//11508
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());  // 내림차순 

	int ans = 0;
	if (n % 3 != 0) {
		for (int i = n - 1; i >= n - (n % 3); i--) {
			ans += v[i];
		}

		v.resize(n - (n % 3));
	}
	
	for (int i = 0;i < v.size(); i += 3) {
		ans += v[i] + v[i + 1];
	}

	cout << ans;
}
