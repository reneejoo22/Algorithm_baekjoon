//11508
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<long long>()); // 내림차순

	long long sum = 0;
	long long tmp;
	for (int i = 0;i < n;i++) {
		tmp = v[i] - i;
		if (tmp > 0) {
			sum += tmp;
		}
		else {
			cout << sum;
			return 0;
		}
	}
	cout << sum;
}
