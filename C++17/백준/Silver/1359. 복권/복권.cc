#include <iostream>
using namespace std;

// 팩토리얼 구하는 함수
int fac(int num) {
	if (num <= 1) {
		return 1;
	}
	else {
		return num * fac(num - 1);
	}
}

int main() {
	int N;		// 1부터 N까지의 수 중 
	int M;		// 서로 다른 M개의 수를 채택	
	int K;		// 적어도 K개가 같으면 당첨		

	int denominator;	// N개 중 M개를 선택할 경우의 수 (분모)
	int numerator;		// 적어도 K개가 같을 경우의 수 (분자)
	double result;

	cin >> N >> M >> K;

	denominator = fac(N) / (fac(M) * fac(N - M));
	numerator = 0;

	for (int i = K; i <= M; i++) {
    		// 지민이와 복권 숫자가 같은 것에서 뽑을 경우의 수 
		int jimin = fac(M) / (fac(i) * fac(M - i));
        	// 지민이와 복권 숫자가 다른 것에서 뽑을 경우의 수 
		int lotto = fac(N - M) / (fac(M - i) * fac(N - M - M + i));
		numerator += jimin * lotto;
	}

	result = double(numerator) / double(denominator);
	cout.precision(10);
	cout << result;

	return 0;
}