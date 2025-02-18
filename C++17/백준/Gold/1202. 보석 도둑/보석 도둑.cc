//19941
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;  //보석 개수, 가방 개수

	vector<pair<int, int>>dia(N);
	for (int i = 0;i < N;i++) {
		cin >> dia[i].first >> dia[i].second;  //무게, 가격
	}

	vector<int>bag(K);
	for (int i = 0;i < K;i++) {
		cin >> bag[i];
	}

	sort(dia.begin(), dia.end());
	sort(bag.begin(), bag.end());

	int idx = 0;
	long totalPrice = 0;
	priority_queue<int>inBag;
	for (int p = 0;p < K;p++) { //가방이 돎. 보석은 통과될때만 인덱스 넘기기
		while(idx<N && bag[p] >= dia[idx].first){
			inBag.push(dia[idx].second);
			idx++;
		}

		if (!inBag.empty()) {
			totalPrice += inBag.top();
			inBag.pop();
		}
	}


	cout << totalPrice;
}