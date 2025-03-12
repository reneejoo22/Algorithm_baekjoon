//22864
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, m;
	cin >> a >> b >> c >> m;

	int ans = 0, day = 24;
	int tired = 0;
	while (day--) {
		if (tired+a <= m) {
			tired += a;
			ans += b;
		}
		else {
			tired -= c;
			if (tired < 0) {
				tired = 0;
			}
		}
	}

	cout << ans;
}