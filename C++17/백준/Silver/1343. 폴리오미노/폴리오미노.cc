//1343
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;  
	//s += ' ';

	int cnt = 0;
	string ans;
	for (int i = 0;i < s.size();i++) {
		
		if (s[i] == 'X') {
			cnt++;
			//cout << cnt <<" s.length() = "<<i << endl;
		}

		if (s[i] == '.') {
			ans += ".";
			if (cnt % 2 != 0) {
				break;
			}
			else cnt = 0;
		}

		if (cnt == 2 && s[i + 1] != 'X') {
			ans += "BB";
			cnt = 0;
		}
		else if (cnt == 4) {
			ans += "AAAA";
			cnt = 0;
		}
	}

	if (cnt % 2 == 1) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}