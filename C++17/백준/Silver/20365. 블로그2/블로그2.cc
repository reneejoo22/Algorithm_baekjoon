//15903
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

	string word;
	cin >> word;

	int b = 0, r = 0;
	if (word[0] == 'B') {
		b++;
	}
	else {
		r++;
	}
	
	for (int i = 1;i < n;i++) {
		if (word[i] != word[i - 1])
			if (word[i] == 'B') {
				b++;
			}
			else
				r++;
	}
	//cout << b << r<<endl;
	int res = min(b, r) + 1;
	cout << res;
}