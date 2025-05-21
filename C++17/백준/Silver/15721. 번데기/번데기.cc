// 15721
#include <iostream>
#include <vector> 
using namespace std;

int main() {
	int a, t, bd;  // 사람 수
	cin >> a>> t>> bd; // 몇번째인지

	int bun = 0, degi = 0;
	int cnt = 2;
	while (1) {
		for (int i = 0;i < 4;i++) {  // 0bun 1degi 2bun 3degi
			if (i % 2 == 0) {
				bun++;
			}
			else {
				degi++;
			}

			if (bun == t && bd == 0) {
				cout << (bun + degi - 1) % a;
				return 0;
			}
			if (degi == t && bd == 1) {
				cout << (bun + degi - 1) % a;
				return 0;
			}
		}

		for (int i = 0; i < cnt;i++){
			bun++;
			if (bun == t && bd == 0) {
				cout << (bun + degi - 1) % a;
				return 0;
			}
		}

		for (int i = 0; i < cnt;i++) {

			degi++;
			if (degi == t && bd == 1) {
				cout << (bun + degi - 1) % a;
				return 0;
			}
		}

		cnt++;

	}

}