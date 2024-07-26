//2023 baekjoon
#include<iostream>
using namespace std;

void DFS(int v, int d);	//그래프 데이터 저장 인접 리스트 // V는 무조건 2,3,5,7 // d는 현재 자리수
bool primeNumber(int num);	//소수인지 확인. 반환값 bool로 해도 상관 ㄴㄴ
int static N;	//지역변수와 전역변수의 성질을 둘 다 가지고 있는 변수

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	//DFS(2, 1); DFS(3, 1); DFS(5, 1); DFS(7, 1);
	
	int a[4] = { 2,3,5,7 };

	for (int j = 0; j < 4; j++) {
			DFS(a[j], 1);
	}
}

//2357_맨 앞의 자리수는 무조건 2,3,5,7. 넷 중 하나
//13579_그외의 자리 수는 1,3,5,7,9. 다섯 중 하나. 
//2,4,6,8 은 어떻게든 소수가 안됨. 그러므로 해당 ㄴㄴ

void DFS(int v, int d) {	//시작 노드, 자리수


	if (d == N) {
		if (primeNumber(v) == 1) {
			cout << v << "\n";
		}
	}

	for (int a = 1; a <= 9; a++) {
		if (a % 2 == 0) {
			continue;	//짝수면 빼버리기
		}
			
		if (primeNumber(v * 10 + a)) {
				DFS(v * 10 + a, d + 1);
		}
	}
}

bool primeNumber(int num){

	for (int i = 2; i <= num/2; i++) {
		if (num % i == 0) {
			return false;	//약수가 하나라도 있으면 false
		}
	}

	return true;
}

//효율적인 코드가 뭔지 생각해보기. 뺄 수 있는 변수면 초반에 빼자