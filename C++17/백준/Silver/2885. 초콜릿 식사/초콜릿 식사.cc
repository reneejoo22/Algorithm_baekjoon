// 2831
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int k;
	cin >> k;  //6

	int choco = 1;

	while (choco < k) {
		choco *= 2;
	}

	int tmp = choco;
	int ans = 0, div = 0;
	while (k!=0) {
		if (k >= tmp) {  // 작으면 데려감
			div = ans;
			k-= tmp;
		}
		// 작지 않으면 k에 빼지 않음으로써 일단 데려가지는 않음
		tmp = tmp / 2;
		ans++;
	}

	cout << choco << " " << div << endl;
}