//1057
#include <iostream>
using namespace std;

int win(int num) {
	return num % 2 == 0 ? num / 2 : num / 2 + 1;
}

int main() {
	int n;
	int kim, lim;

	cin >> n >> kim >> lim;

	int round = 0;
	while (kim != lim) {
		round++;
		kim = win(kim);
		lim = win(lim);
	}

	cout << round;
}