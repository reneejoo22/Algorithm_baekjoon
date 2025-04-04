//1969
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c[51][4];

int main() {
	
	int n, m;
	cin >> n >> m;

	vector<string>v(n);
	for (int i = 0;i < n;i++) {
		string data;
		cin >> data;
		for (int q = 0;q < m;q++) {
			if (data[q] == 'A') c[q][0]++;
			else if (data[q] == 'C')c[q][1]++;
			else if (data[q] == 'G')c[q][2]++;
			else if (data[q] == 'T')c[q][3]++;
		}
	}
	string ans = "";
	int sum = 0;
	for (int i = 0;i < m;i++) {
		int maxCnt = 0, maxIdx = 0;
		for (int j = 0;j < 4;j++) {
			if (c[i][j] > maxCnt) {
				maxCnt = c[i][j];
				maxIdx = j;
			}
		}
		if (maxIdx == 0) ans += "A";
		else if (maxIdx == 1) ans += "C";
		else if (maxIdx == 2) ans += "G";
		else if (maxIdx == 3) ans += "T";
		sum += (n - maxCnt);
	}
	cout << ans << "\n" << sum;
}