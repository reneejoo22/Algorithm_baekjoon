// 15721
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

long long alpha[10];
long long noZ[10];

int main() {
	int n;  // 사람 수
	cin >> n; // 몇번째인지

	for (int i = 0;i < n;i++) {
		string word;
		cin >> word;
		noZ[word[0] - 'A'] = 1;

		long long k = 1;
		for (int j = word.size() - 1;j >= 0;j--) {
			alpha[word[j] - 'A'] += k;   // 1
			k *= 10;  // 10  // 최종적으로 맨 앞자리수가 1000...이 됨
		}
	}

	bool flag = 0;
	for (int i = 0;i < 10;i++) {
		if (!alpha[i]) {
			flag = 1;
		}
	}
	
	if (!flag) {
		// A부터 J까지의 모든 알파벳이 사용된 경우에는 어딘가에 0을 줘야 함
		long long min = 10000000000000000;
		int idx = 0;
		for (int i = 0;i < 10;i++) {
			if (!noZ[i] && alpha[i] < min) {  //최솟값보다 작고 앞자리가 아닌 것
				min = alpha[i];
				idx = i;
			}
		}
		alpha[idx] = 0;
	}

	sort(alpha, alpha + 10, greater<>());  // 내림차순

	long long ans = 0;
	for (int i = 0, j = 9;i < 10;i++, j--) {
		ans += alpha[i] * j;
	}
	cout << ans;

}