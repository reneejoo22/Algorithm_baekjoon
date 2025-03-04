//11501
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string a, b;
	
	cin >> a;
	cin >> b;

	if (b.size() <= a.size()) {
		cout << 0;
		return 0;
	}

	while(true) {
		if (b[b.size()-1] == 'A') {
			b.pop_back();
		}
		else {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
		if (b.size() == a.size()) {
			if (a == b) cout << 1;
			else cout << 0;
			break;
		}
	}
}