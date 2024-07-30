//baekjoon 1940
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int N;
	cin >> N;

	vector<int>A(N, 0);

	for (int q = 0; q < N; q++) {
		cin >> A[q];
	}

	sort(A.begin(), A.end());

	int res = 0;

	for (int k = 0; k < N; k++) {
		long find = A[k];
		int i = 0;
		int j = N - 1;

		while (i < j) {
			if (A[i] + A[j] == find) {
				if (i != k && j != k) {
					res++;
					break;
				}
				else if (i == k) {
					i++;
				}
				else if (j == k) {
					j--;
				}
			}

			else if (A[i] + A[j] < find) {
				i++;
			}
			else {
				j--;
			}
		}
	}

	cout << res;
}
