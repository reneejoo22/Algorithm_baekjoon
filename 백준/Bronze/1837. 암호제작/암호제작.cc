//1837
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define MAX (1000000+3)
#define INF (1000000000)

bool isNotPrimenumber[MAX];		// true 소수 아님  / false 소수

string inputStr;
int K;

int ans;	//맞춘 횟수

void makePrimenumber() {
	// 0-1. 에라토스테네스의 체
	for (int i = 2; i * i < MAX; i++)
	{
		if (isNotPrimenumber[i] == false) {
			for (int j = i * i; j < MAX; j += i)
			{
				isNotPrimenumber[j] = true;
			}
		}
	}
}

int main() {
	// 0. 소수 만들기
	makePrimenumber();

	// 1. 입력
	
	cin >> inputStr;
	scanf("%d", &K);

	
	int tmp;
	ans = INF; 
	for (int i = 2; i < K; i++) {
		tmp = 0;
		// 소수만 취급
		if (isNotPrimenumber[i]) {
			continue;
		}
		for (int j = 0; j < inputStr.size(); j++) {
			tmp = (tmp * 10 + inputStr[j] - '0') % i;
		}
		if (tmp == 0) {
			ans = i;
			break;
		}
	}

	if (ans < K) {
		printf("BAD %d", ans);
	}
	else {
		printf("GOOD");
	}

	return 0;
}