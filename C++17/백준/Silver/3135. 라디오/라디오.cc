//11508
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		int num;
		cin >> num;
		num = abs(num - b);
		v[i] = num;
	}

	sort(v.begin(), v.end());  // 내림차순 

	int anotherWay = abs(a - b);
	if (v[0] < anotherWay) {
		cout << v[0] + 1;
	}
	else {
		cout << anotherWay;
	}

}
