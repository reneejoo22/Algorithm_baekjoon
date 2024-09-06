//4740
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char word[81];

	while (true) {
		cin.getline(word, 81, '\n');

		if (!strcmp(word,"***")) {
			break;
		}
		else {
			for (int i = strlen(word) - 1; i >= 0; i--) {
				cout << word[i];
			}
			cout << "\n";
		}
	}
}

//getline(대상문자열, 저장할 곳, 나눌 기준)