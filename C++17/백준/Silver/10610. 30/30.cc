//10610
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	string p;
	cin >> p;

	int sum = 0;
	bool isZ = false;
	for (int i = 0;i < p.size();i++) {
		v.push_back(p[i]-'0');

		sum += v[i];

		if (v[i] == 0) {
			isZ = true;
		}
	}

	if (isZ && sum % 3 == 0) {
		sort(v.begin(), v.end(), greater<int>());
		for (int z = 0; z < v.size();z++) {
			cout << v[z];
		}
	}
	else {
		cout << "-1";
	}

}