//1443
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;

	vector<int>pos(N);
	for (int i = 0;i < N;i++) {
		cin >> pos[i];
	}

	sort(pos.begin(), pos.end());

	int cnt = 0;
	double end = 0;

	for (int i = 0;i < N;i++) {
		if (pos[i] > end) {
			cnt++;
			end = pos[i] + L - 1;
		}
	}

	cout << cnt;
}