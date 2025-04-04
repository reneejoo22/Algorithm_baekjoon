//27961
#include <iostream>
using namespace std;

int main() {
	
	long long n;
	cin >> n;

	long long ans = 0, a = 0;  //마법 횟수, 고양이수
	while (a < n) {
		if (a == 0) {
			a++;
		}
		else {
			a *= 2;
		}
		ans++;
	}

	cout << ans;
}
