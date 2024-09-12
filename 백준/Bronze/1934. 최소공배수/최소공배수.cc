//1934
#include<iostream>
using namespace std;

int gcd(int a, int b);

int main() {
	int t;
	cin >> t;

	int a, b;

	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << a * b / gcd(a, b) << endl;
	}
}

int gcd(int a, int b) {	// 6 10
	if (b == 0) { //a가 최대공약수
		return a;
	}
	else {
		return gcd(b, a % b);	//최대공약수를 구하는 알고리즘
	}
}

/*
gcd(10, 6)

return gcd(6, 2)

return(2,4)

return (4, 2)

return (2, 0)

return 2;


*/