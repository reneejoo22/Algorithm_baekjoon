//15903
#include <iostream>
#include <string>
using namespace std;

int main() {
	string guess = "";
	getline(cin,guess);

	string ans = "UCPC";

	int idx = 0;
	for (int i = 0;i < guess.length();i++) {
		
		if (ans[idx] == guess[i]) {
			// cout << "찾음_" << ans[idx] << "_idx: " << idx << endl;
			idx++;
			if (idx == 4) {
				cout << "I love UCPC";
				return 0;
			}

		}
	}

	cout << "I hate UCPC";
}
