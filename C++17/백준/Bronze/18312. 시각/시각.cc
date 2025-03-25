#include <iostream>
using namespace std;

int main(void) {

	int N, K, num = 0;
	cin >> N >> K;

	for (int hour = 0; hour <= N; hour++) {
		for (int minute = 0; minute < 60; minute++) {
			for (int sec = 0; sec < 60; sec++) {
				if (hour % 10 == K || hour / 10 == K ||
					minute % 10 == K || minute / 10 == K ||
					sec % 10 == K || sec / 10 == K)
					num++;
			}
		}
	}
	cout << num;
}