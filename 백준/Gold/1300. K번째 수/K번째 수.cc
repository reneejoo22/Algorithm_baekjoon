#include<iostream>
using namespace std;

int main() {

	int N, K;
	
	cin >> N;
	cin >> K;

	int start = 1, end = K;
	int middle, cnt, ans;

	while (start <= end) {
		middle = (start + end) / 2;	//4
		cnt = 0;	//중앙값보다 작거나 같은 값들
		
		for (int i = 1; i <= N; i++) {	//각 행에서 중앙값보다 작은 수의 갯수를 알아내기 
			cnt = cnt + min(middle / i, N);	//뭐가 되었든 갯수가 N보다 클수 없
		}
		//cout << cnt << "\n";

		if (cnt < K) {
			start = middle + 1;
		}
		else {
			end = middle - 1;
			ans = middle;
		}
	}
	cout << ans;
}

/*
N = 3, K= 7

A[N][N] 이라는 2차원 배열이랑 B[N*N] 라는 1차원 배열이 생성됨.

A[3][3] 이라는 2차원 배열이 생성됨.
A[i][j] = i*j 이다.
아래와 같은 모양

    [1] [2] [3]
[1]  1   2   3
[2]  2   4   6
[3]  3   6   9

B[3*3] 즉 B[9]
B 는 A안에 들어있는 값을 전부 오름차순한 형태
아래와 같은 모양

B = { 1,  2,  2,  3,  3,  4,  6,  6,  9 }
     [0] [1] [2] [3] [4] [5] [6] [7] [8]

여기서 우리가 구해야하는 값은 B[7]

====================<round 1>
1~K(7) 안에 답이 있음.
그러므로 start = 1, end = K(7) 로 설정. 이 안에서 찾자!
middle = (start+end)/2 = 4 //중앙값
cnt = 중앙값보다 작거나 같은 값들

	[1] [2] [3]
[1]  1   2   3		middle(4)/1 = 4	//한 열마다 3개씩 있음으로 4개가 있을 수 있음
[2]  2   4   6		middle(4)/2 = 2 
[3]  3   6   9		middle(4)/3 = 1

min(middle/i,N) 이걸 사용해서 각 열마다 있는 4보다 작은 값을 구함
cnt = 6;
cnt(중앙값 4보다 작거나 같은 값의 갯수) < K(6)이면 
start = middle + 1 = 5;

====================<round 2>

5~K(7) 안에 답이 있음.
그러므로 start = 5, end = K(7) 로 설정. 이 안에서 찾자!
middle = (start+end)/2 = 6 //중앙값
cnt = 중앙값보다 작거나 같은 값들

	[1] [2] [3]
[1]  1   2   3		middle(6)/1 = 6	//한 열마다 3개씩 있음으로 6개가 있을 수 있음
[2]  2   4   6		middle(6)/2 = 3
[3]  3   6   9		middle(6)/3 = 2

min(middle/i,N) 이걸 사용해서 각 열마다 있는 4보다 작은 값을 구함
cnt = 8;
cnt(중앙값 6보다 작거나 같은 값의 갯수) >= K(6)이면

end = middle - 1 = 5; 저장
ans = middle(6); 저장

start 랑 end 가 같은 값이 되었으니 반복문 종료
*/