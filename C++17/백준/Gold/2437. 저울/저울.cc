#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;

	vector<int>v;
	for (int i = 0;i < t;i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int sum = 0;
	for (int a = 0;a < t;a++) {
		if (v[a] > sum + 1) {  // 1-1, 1-3, 2-5, 3-8, 6-14, 7-21, 30
			break;
		}
		sum += v[a];
	}

	cout << sum+1;
	return 0;
}

/*
1 1 2 3 6  7  30
1 2 4 7 13 20 50
*/