//1969
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

	sort(v.begin(), v.end());

	if (n % 2 == 1) {
		cout << v[n / 2];
	}
	else {
		cout << v[n / 2 - 1];
	}

}
