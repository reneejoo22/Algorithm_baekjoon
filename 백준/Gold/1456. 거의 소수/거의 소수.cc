//1456
#include<iostream>
#include<cmath>
using namespace std;

#define largeNum 10000001

int main() {
	
	long start, end;
	cin >> start >> end;	//1, 1000
	long A[largeNum];	//현존하는 모든 소수 구하기

	for (int i = 2; i < largeNum; i++) {	//0과 1은 안 넣음
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(largeNum); i++) {	//제곱근까지 수행 //2//3//4
		if (A[i] == 0) {
			continue;
		}
		for (int j = i + i; j < largeNum; j = j + i) {	//*1
			A[j] = 0;
		}
	}

	int count = 0;

	for (int p = 2; p < largeNum; p++) {
		if (A[p] != 0) {	//소수이면
			long temp = A[p];

			while ((double)A[p] <= (double)end / (double)temp) {	//*2
				if ((double)A[p] >= (double)start / (double)temp) {
					count++;
				}
				temp = temp * A[p];
			}
		}
	}

	cout << count << "\n";

}

//-------------------------
// 1)
// 배수의 첫 수는 제외하고 지우기
// firstRound_4, 6, 8, 10, 12, 14, 16.....
// secondRound_6, 9, 12, 15, 18, 21.....
// thirdRound_8, 16, 24, 32, 40, 48.....

//-------------------------
// 2)
// 예시_2,3,5,7
// firstRound(2)_ 
// 
// 2 <= 500 만족일때 돌아감
// 2 >= 0.5 _충족_count = 1
//temp = 2*2 = 4
// 
// 2 <= 250 만족일때 돌아감
// 2 >= 0.25 _충족_count = 2
// temp = 4*2 = 8
// 
// 2 <= 125 만족일때 돌아감
// 2 >= 0.125 _충족_count = 3
// temp = 8*2 = 16
// 
// 2 <= 62.5 만족일때 돌아감
// 2 >= 0.0625 _충족_count = 4
// temp = 16*2 = 32
// 
// 2 <= 31.25 만족일때 돌아감
// 2 >= 0.03125 _충족_count = 5
// temp = 32*2 = 64
// 
// 2 <= 15.625 만족일때 돌아감
// 2 >= 0.015625 _충족_count = 6
// temp = 64*2 = 128
// 
// 2 <= 7.8125 만족일때 돌아감
// 2 >= 0.03125 _충족_count = 7
// temp = 128*2 = 256
// 
// 2 <= 3.90625 만족일때 돌아감
// 2 >= 0.015625 _충족_count = 8
// temp = 256*2 = 514
//
// 2 <= 1.953125 만족 못 함 종료_ 다음 소수로 넘어감



//-----------
/*

while (A[p] <= end) {	//*2
				if (A[p] >= start) {
					count++;
				}
				temp = temp * A[p];
			}
			//이건 될수가 없음
			A[p]의 값은 변하지 않는 소수 값임
			그렇다고 temp >= start 이렇게 쓸 수도 당연 없음. 
			그러면 범위를 벗어난 소수도 세게 됨.

*/