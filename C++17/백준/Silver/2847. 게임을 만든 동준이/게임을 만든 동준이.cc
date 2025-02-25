//2847
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>score(n);
	for (int i = 0;i < n;i++) {
		cin >> score[i];
	}

	int cnt = 0;
	for (int p = n-1; p >= 1; p--) {
		while (score[p] <= score[p - 1]) {
			score[p - 1]--;
			cnt++;
		}
	}

	cout << cnt;;
}