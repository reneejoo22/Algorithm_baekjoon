#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
int n;
ll map[10100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &map[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += abs(map[i] - map[j]);
		}
	}
	cout << ans << endl;
}