#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int n = 0;
	int a;
	int max = -1000000, min = 1000000;

	if (scanf("%d", &n) == 0) { printf("error"); };

	for (int i = 0; i < n; i++) {
		if (scanf("%d", &a) == 0) { printf("error2"); };
		if (max < a)max = a;
		if (min > a)min = a;
	}

	printf("%d %d", min, max);

}