#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int cnt = 1;
	while (true) {

		if (a == b) {
			break;
		}
		else if (a > b) {
			cnt = -1;
			break;
		}

		if (b % 2 == 0) {
			cnt++;
			b /= 2;
		}
		else if (b % 10 == 1) {	//2로 나눠지지 않는 경우 =! 끝자리수가 1
			b /= 10;
			cnt++;
		}
		else {
			cnt = -1;
			break;
		}
	}
	cout << cnt << endl;

}