//15903
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());  // 내림차순

	int ans = 0;
	priority_queue<int>pq;
	for (int i = 0;i < n; i++) {
		pq.push(v[i] + i + 1);
	}

	cout << pq.top() + 1;

}
