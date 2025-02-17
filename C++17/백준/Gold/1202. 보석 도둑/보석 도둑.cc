#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compareP(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
} // 보석 무게 기준 오름차순 정렬

int main() {
    int N, K; // 보석 수, 가방 개수
    cin >> N >> K;

    vector<pair<int, int>> dia(N);
    for (int i = 0; i < N; i++) {
        int m, v; // 무게, 가격
        cin >> m >> v;
        dia[i] = {v, m}; 
    }

    vector<int> bag(K);
    for (int p = 0; p < K; p++) {
        cin >> bag[p];
    }

    sort(dia.begin(), dia.end(), compareP); // 보석 무게 오름차순 정렬
    sort(bag.begin(), bag.end());           // 가방 무게 오름차순 정렬

    priority_queue<int> inBag;
    long long totalPrice = 0;
    int idx = 0;

    for (int q = 0; q < K; q++) {
        while (idx < N && dia[idx].second <= bag[q]) { 
            inBag.push(dia[idx].first); // 가격을 넣음 (최대 힙)
            idx++;
        }
        
        if (!inBag.empty()) {
            totalPrice += inBag.top(); // 가장 비싼 보석을 선택
            inBag.pop();
        }
    }

    cout << totalPrice;
}
