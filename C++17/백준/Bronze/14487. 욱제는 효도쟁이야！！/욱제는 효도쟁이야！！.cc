//14487
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>path(n);
	int max = 0, shortPath = 0;
	for (int i = 0;i < n;i++) {
		cin >> path[i];
		if (max < path[i]) {
			max = path[i];
		}
		shortPath += path[i];
	}

	shortPath -= max;
	cout << shortPath;
	
}