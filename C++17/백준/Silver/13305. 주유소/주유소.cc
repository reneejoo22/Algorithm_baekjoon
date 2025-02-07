//13305
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int c;
	cin >> c;
	
	vector<pair<int, int>> v(c, {0,0});
	int num;int min = 1000000001;

	for (int i = 0;i < c - 1;i++) {	
		cin >> num;
		v[i].second = num;
	}

	for (int i = 0;i < c;i++) {
		cin >> num;
		v[i].first = num;
	}

	long ans = 0;
	int q = 0;
	for (int q = 0;q < c - 1;q++) {
		if (v[q].first < min) {
			min = v[q].first;
		}
		ans += min * v[q].second;
	}
	
	cout<< ans;
}