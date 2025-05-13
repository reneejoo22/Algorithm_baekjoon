// 2831
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100

int main() {

	int k;
	cin >> k;  //6


	int coin[MAX] = { 0 };
	for (int i = 1;i <= MAX;i++) {
		coin[i] = coin[i - 1] + 1;
		if (i - 10 >= 0) {  // 10, 11
			coin[i] = min(coin[i], coin[i - 10] + 1);   // 1 or 10_ 10원
		}
		if (i - 25 >= 0) {
			coin[i] = min(coin[i], coin[i - 25] + 1);  // 25원 사용하고 남은 돈
		}
	} // 100으로 나눌 수 있음


	
	for (int i = 0;i < k;i++) {
		long long num;
		cin >> num;
		long long ans = 0;
		
		while (num) {
			ans += coin[num % 100];
			num /= 100;  
		}
		cout << ans << endl;
	}

	return 0;
}