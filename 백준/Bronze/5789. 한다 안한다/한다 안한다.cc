//5789
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string w;
		cin >> w;

		if (w[w.length() / 2] == w[(w.length() / 2) - 1]) {
			cout << "Do-it\n";
		}
		else {
			cout << "Do-it-Not\n";
		}
	}
}