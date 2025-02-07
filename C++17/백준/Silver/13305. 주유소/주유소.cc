//13305
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int c;
	cin >> c;
	
	vector<pair<int, int>> v(c, {0,0});
	int num;
	int totalK = 0;

	for (int i = 0;i < c - 1;i++) {	
		cin >> num;
		v[i].second = num;
		totalK += num;
	}


	int min = 99999;
	for (int i = 0;i < c;i++) {
		cin >> num;
		v[i].first = num;
		if (min > num) {
			min = num;
		}
	}

	int ans = 0;
	int q = 0;
	while (v[q].second != 0) {
		if (min == v[q].first) {
			ans+= v[q].first * totalK;
			cout << ans;
			return 0;
		}
		else if (v[q].first < v[q + 1].first) {
			ans += v[q].first * (v[q].second + v[q + 1].second);
			totalK -= v[q].second + v[q + 1].second;
			q += 2;
		}
		else {
			ans += v[q].first * v[q].second;
			totalK -= v[q].second;
			q++;
		}
	}
	
	cout<< ans;
}