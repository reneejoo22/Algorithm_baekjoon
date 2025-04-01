//11508
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int,int>>v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());  // 내림차순 

	int time = 0;
	for (int i = 0;i < n; i++) {
		time = max(time, v[i].first);
		time += v[i].second;
	}
	cout << time;
}