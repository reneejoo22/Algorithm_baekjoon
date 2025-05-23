// 15721
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
#define MAX 100100

bool lane[MAX];

int main() {
	int x,y,a,b;  // 사람 수
	cin >> x >> y >> a >> b; // 몇번째인지

	int idx;
	for (int i = a;i < MAX;i+=x) {
		lane[i] = true;
	}

	for (int i = b;i < MAX;i += y) {
		if (lane[i]) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}