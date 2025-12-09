#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int chang = 100, sang = 100;	
	
	//vector<pair<int, int>>score(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) sang -= a;
		else if (a < b) chang -= b;
	}

	cout << chang << "\n" << sang;

}