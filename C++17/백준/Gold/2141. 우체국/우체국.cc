//2141
#include <iostream>
#include <climits>
#include<algorithm>
using namespace std;

pair<long long, long long>map[100001];
long long sum;
int n;

int main() {
	cin >> n;

	for (int i = 1;i <= n;i++) {
		cin >> map[i].first >> map[i].second;
		sum += map[i].second;
	}

	sort(map+1, map+1+n);

	long long cur = 0;
	for (int i = 1;i <= n;i++) {
		cur += map[i].second;
		if (cur >= (sum + 1) / 2) {
			cout << map[i].first;
			break;
		}
	}
}
