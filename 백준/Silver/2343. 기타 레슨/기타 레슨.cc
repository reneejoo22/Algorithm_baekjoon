//2343
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M;	//강의수9, 블루레이 갯수3_27
	cin >> N >> M;

	vector<int>A(N);

	int start = 0, end = 0;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (start < A[i]) {
			start = A[i];	//레슨의 최댓값_9
		}
		end = end + A[i];	//모든 레슨의 값을 종료 인덱스에 저장_45
	}

	int middle, sum, count;

	while (start <= end) {

		middle = (start + end) / 2;
		sum = 0;
		count = 0;

		for (int j = 0; j < N; j++) {
			if (sum + A[j] > middle) {
				count++;
				sum = 0;
			}
			sum = sum + A[j];
		}

		if (sum != 0) {
			count++;
		}
		if (count > M) {
			start = middle + 1;
		}
		else {
			end = middle - 1;
		}

	}
	
	cout << start;
}