#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, K;	//종류 갯수, 가치의 합
	cin >> N >> K;

	vector<int>A(N);

	for (int i = 0; i < N; i++) {	
		cin >> A[i];
	}

	int count = 0;

	for (int j = N - 1; j >= 0; j--) {
		if (K == 0) {
			break;
		}

		if (A[j] <= K) {
			count += (K / A[j]);
			K = K % A[j];
		}
	}

	cout << count;

}