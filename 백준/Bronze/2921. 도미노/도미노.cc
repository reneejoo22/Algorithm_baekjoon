//2921
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			count += i + j;
		}
	}

	cout << count;
}
/*
0 0
1 0, 1 1_3
2 0, 2 1, 2 2_9
_12
*/