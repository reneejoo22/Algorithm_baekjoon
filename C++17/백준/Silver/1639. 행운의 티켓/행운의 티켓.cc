#include <stdio.h>

char s[51];

bool Is_Lucky(int start, int end) {

	int sum1 = 0, sum2 = 0, mid = (start + end) / 2;

	for (int i = start; i < mid; i++) sum1 += s[i] - '0';

	for (int i = mid; i < end; i++) sum2 += s[i] - '0';

	// 양쪽 합이 같으면 행운 티켓

	if (sum1 == sum2) return true;

	return false;

}

int main() {

	int len = 0;

	scanf("%s", s);

	while (s[len++] != NULL); // 문자열 길이 구하기

	// 가장 긴 것부터 계산해서 행운이면 바로 코드 종료

	for (int i = len - 1; i >= 0; i--) {

		// 행운 티켓은 2N자리이므로 짝수 자릿수만 계산

		if (i & 1) continue;

		for (int j = 0; j < len - i; j++) {

			if (Is_Lucky(j, j + i)) {

				printf("%d", i);

				return 0;

			}

		}

	}

	return 0;

}