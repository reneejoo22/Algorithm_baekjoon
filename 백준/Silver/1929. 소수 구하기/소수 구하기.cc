//1929
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {

	int start, end;		//3,16
	cin >> start >> end;

	vector<int>A(end + 1);		//17
	for (int i = 2; i <= end; i++) {	//0과 1은 안 넣음
		A[i] = i;
	}

	for (int i = 2; i <= sqrt(end); i++) {	//제곱근까지 수행 //2//3//4
		if (A[i] == 0) {
			continue;
		}
		for (int j = i + i; j <= end; j = j + i) {	//*1
			A[j] = 0;
		}
	}

	for (int p = start; p <= end; p++) {
		if (A[p] != 0) {
			cout << A[p] << "\n";
		}
	}

}

//-------------------------
// 1)
// 배수의 첫 수는 안 지운다
// firstRound_4, 6, 8, 10, 12, 14, 16
// secondRound_6, 9, 12, 15
// thirdRound_8,16
