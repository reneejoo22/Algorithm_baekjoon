//1202
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N, K; //보석 수, 가방 갯수
	cin >> N >> K;

	vector<pair<int, int>> dia(N);
	for (int i = 0;i < N;i++) {
		int m, v; //무게, 가격
		cin >> m >> v;
		dia[i] = { m , v }; 
	}

	vector<int>bag(K);
	for (int p = 0;p < K;p++) {
		cin >> bag[p];
	}

	sort(dia.begin(), dia.end());	//오름차순 정렬// 계속 무게 맞나 비교가 비효율적
	sort(bag.begin(), bag.end());

	priority_queue<int>inBag;
	long long totalPrice = 0;
	int idx = 0;

	for (int q = 0;q < K;q++) {
		while (idx < N && dia[idx].first <= bag[q]) {
			inBag.push(dia[idx].second);
			idx++;
		}
		//시간초과 문제 때문에 담을 수 있는것만 따로 뺌
		if (!inBag.empty()) {
			totalPrice += inBag.top();
			inBag.pop();
		}
	}
	
	cout << totalPrice;
}