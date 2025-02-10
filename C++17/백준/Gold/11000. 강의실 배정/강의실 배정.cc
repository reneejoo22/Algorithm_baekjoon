//11000
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	int c;
	cin >> c;
	
	vector<pair<int, int>> v;
	priority_queue<int, vector<int>, greater<int>>pq;

	int s,e;
	for (int i = 0; i < c; i++) {	
		cin >> s >> e;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end());	//first 값이 같으면 second 값 기준으로 정렬

	pq.push(v[0].second);
	for (int q = 1;q < v.size();q++) {
		if (v[q].first >= pq.top()) {
			pq.pop();
			pq.push(v[q].second);
		}
		else {
			pq.push(v[q].second);
		}
	}

	cout << pq.size() << endl;
}