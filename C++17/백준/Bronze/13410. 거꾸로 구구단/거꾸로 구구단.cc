//13410
#include <iostream>
#include<vector>
using namespace std;

int reverse(int n) {
	int res = 0;

	while (n > 0) {
		res = res * 10 + n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	
	int n,m;
	cin >> n >> m;

	int tmp;
	int max = -1;
	for (int i = 0;i < m;i++) {
		tmp = reverse(n*(i+1));
		if (max < tmp) {
			max = tmp;
		}
	}
	cout << max;
}
