//13410
#include <iostream>
#include<queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<pair<int, int>>v;
	priority_queue<int,vector<int>, greater<int>>pq;  // 정수형 저장, 벡터 방식으로, 오름차순...
	for (int i = 0;i < n;i++) {
		int t, p;
		cin >> t >> p;
		v.push_back({ t,p });
	}

	sort(v.begin(), v.end());  // 마감시간 기준 오름차순
	for (int i = 0;i < n;i++) {
		pq.push(v[i].second);
		if (v[i].first < pq.size()) {  // 데드라인 < 현재 시간
			pq.pop();
		}
	}

	int food = 0;
	while (!pq.empty()) {
		food += pq.top();
		pq.pop();
	}

	cout << food;

}
