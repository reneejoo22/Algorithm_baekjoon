//1016
#include<iostream>
#include<vector>
using namespace std;

long long number[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;	//1, 10
	cin >> min >> max;

    int cnt = 0;

	
    for (long long i = 2; i * i <= max; i++) {
        long long n = min / (i * i);

        if (min % (i * i)) n++;

        while (n * i * i <= max) {		//n*i*i는 min보다 크거나 같은 i의 제곱수의 배수
            number[n * i * i - min] = 1;
            n++;
        }
    }

    for (int i = 0; i <= max - min; i++) {
        if (number[i] == 0) cnt++;
    }

    printf("%d", cnt);
    return 0;
}

//  1) --------------------
/*  예: pow = 4이면 4 * j로 4의 배수를 찾는 과정)
i = 2:

pow = 2 * 2 = 4
start_index = min / pow = 1 / 4 = 0
나머지가 0이 아니므로 start_index++ → start_index = 1

j = 1:
for (j = 1; 4(4 * j) <= max(10); j++)에서, j가 증가하면서 
pow* j가 max보다 작은 동안 반복.
A[4-1 = 0] = true_ 숫자 4_ true

j = 2:
for (j = 2; 8(4 * j) <= max(10); j++)에서, j가 증가하면서
pow* j가 max보다 작은 동안 반복.
A[8-1 = 7] = true_ 숫자 8_ true

= = = = = = = = = = = = = = = = = = =

i = 3:

pow = 3 * 3 = 9
start_index = min / pow = 1 / 9 = 0
나머지가 0이 아니므로 start_index++ → start_index = 1

j = 1:
for (j = 1; 9(9 * j) <= max(10); j++)에서, j가 증가하면서
pow* j가 max보다 작은 동안 반복.
A[9-1 = 0] = true_ 숫자 9_ true


*/