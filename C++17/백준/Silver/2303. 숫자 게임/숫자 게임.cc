#include <iostream>
using namespace std;

int c[1000][5]; //카드값 저장 배열
int score[1000]; //합의 일의 자리수 최대값

int main() {

	int input;  
	cin >> input; //사람 수 입력
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < 5; j++){
			cin >> c[i][j]; //카드값 c에 저장
		}
	}
	int max = 0; //일의 자리 수가 가장 큰 경우의 값
	int num = 0; //max값일때 인덱스
    
    //각 사람별 합의 일의 자리수 최대값 구하는 과정
	for (int i = 0; i < input; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = j + 1; k < 5; k++) {
				for (int l = k + 1; l < 5; l++) {
					if (score[i] < (c[i][j] + c[i][k] + c[i][l])%10)
						score[i] = (c[i][j] + c[i][k] + c[i][l])%10;
				}
			}
		}
	}

    //일의 자리 수가 가장 큰 경우와, 해당 인덱스 구하기 
	for (int i = 0; i < input; i++) {
		if (max < score[i]) {
			max = score[i];
			num = i;
		}
        //값이 같은 경우 더 큰 번호로 저장
		if (max == score[i]) {
			if (i > num) num = i;
		}
	}
	cout << num+1 << endl;

	return 0;
}