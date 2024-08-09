//2476
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int max = 0, maxSum = 0;

	for (int p = 0; p < n; p++) {
		int a, b, c;
		cin >> a >> b >> c;

		sum = 0;
		if (a == b && b == c) {	//다 맞는 경우
			sum = 10000 + (1000 * a);
			//cout << "다 올0" << sum << "\n";
		}

		else if (a != b && b != c && a != c) { //하나도 맞는게 없는 경우
			max = a;

			if (max < b) {
				max = b;
			}
			if (max < c) {
				max = c;
			}

			sum = max * 100;
			//cout << "다 올ㄴ" << sum << "\n";
		}

		else {	
			if (a == b) {
				sum = 1000 + (a * 100);
			}
			else if (b == c) {
				sum = 1000 + (b * 100);
			}
			else if (a == c) {
				sum = 1000 + (c * 100);
			}
			//cout << "2개" << sum<<"\n";
		}

		if (maxSum < sum) {
			maxSum = sum;
		}
	}

	cout << maxSum;
}