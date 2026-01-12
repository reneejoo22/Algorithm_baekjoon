// 2961
#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;


int main() {
	ll ans = 2147499999;

	ll n;
	cin >> n;
	vector<pair<ll, ll>>v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 1; i < (1 << n); i++) { // (2^n) - 1 까지 반복... 재료 하나 이상 쓰기
		ll sour = 1, bitter = 0; // 신건 곱, 쓴건 합
		for (int x = 0; x < n; x++) {
			/*
				x = 0 → 0번 재료 확인
				x = 1 → 1번 재료	확인
				x = 2 → 2번 재료 확인	
			*/
			if (i & (1 << x)) {  // i 안에 x가 있냐? 3안에 1이 있나
				// cout << "when i " << i<<" 1<<x "<< (1<<x) << endl;
				sour *= v[x].first;
				bitter += v[x].second;
			}
		}
		ans = min(ans, abs(sour - bitter));
		// cout << "min - " << ans << endl;
	}
	cout << ans << endl;
}
/*
2
3 8
5 8
*/