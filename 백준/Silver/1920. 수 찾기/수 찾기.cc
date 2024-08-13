//1920
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>A(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	int fn;
	cin >> fn;

	int midi, midiv;
	bool find;
	int start, end;

	for (int i = 0; i < fn; i++) {
		find = false;

		int target;
		cin >> target;

		start = 0, end = A.size() - 1;

		while (start <= end) {
			midi = (start + end) / 2;
			midiv = A[midi];

			if (midiv > target) {
				end = midi - 1;
			}
			else if (midiv < target) {
				start = midi + 1;
			}
			else {
				find = true;
				break;
			}
		}

		if (find) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	};
}