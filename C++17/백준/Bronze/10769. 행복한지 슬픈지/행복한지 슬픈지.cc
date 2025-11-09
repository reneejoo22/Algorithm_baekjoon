#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;	getline(cin, str);
	int cnt(0);
	bool isFlag = false;
	for (string::iterator i = str.begin(); i != str.end(); i++) {
		if (*i == ':' && *(i + 1) == '-') {
			if (*(i + 2) == ')'){
				cnt++; 
				isFlag = true;
			}
			else if (*(i + 2) == '(') {
				cnt--; 
				isFlag = true; 
			}
		}
	}

	if (cnt > 0) cout << "happy";
	else if (cnt == 0 && isFlag) cout << "unsure";
	else if (cnt == 0 && !isFlag) cout << "none";
	else cout << "sad";
}