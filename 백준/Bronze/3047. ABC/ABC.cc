//3047
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

	vector<pair<int, char>>A(3);

	for (int i = 0; i < 3; i++) {
		cin >> A[i].first;
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < 3; i++) {
		cin >> A[i].second;
	}

	for (int i = 0; i < 3; i++) {
		if (A[i].second == 'A') {
			cout << A[0].first << " ";
		}
		else if (A[i].second == 'B') {
			cout << A[1].first << " ";
		}
		else if (A[i].second == 'C') {
			cout << A[2].first << " ";
		}
	}
}
