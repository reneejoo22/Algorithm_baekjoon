//2847
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n>>m;

	vector<string>A(n);
	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}

	vector<string>B(n);
	for (int i = 0;i < n;i++) {
		cin >> B[i];
	}

	int cnt = 0;
	for (int p = 0;p <= n - 3;p++) {
		for (int q = 0;q <= m - 3;q++) {
			if (A[p][q] != B[p][q]) {

				for (int z = p;z < p + 3;z++) {
					for (int x = q;x < q + 3;x++) {
						if (A[z][x] == '0') A[z][x] = '1';
						else A[z][x] = '0';
					}
				}
				cnt++;
			}
		}
	}


	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt;
}