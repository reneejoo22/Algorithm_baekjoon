//19941
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<char>seat(N);
	int hNum = 0;
	for (int i = 0;i < N;i++) {
		cin>> seat[i];
	}

	int ans = 0;
	for (int p = 0;p < N;p++) {
		if (seat[p] == 'H') {
			for (int q = p - K;q <= p + K;q++) {
				if (q >= 0 && q < N && seat[q] == 'P') {
					ans++;
					seat[q] = '-';
					break;
				}
			}
		}
	}

	cout << ans;
}