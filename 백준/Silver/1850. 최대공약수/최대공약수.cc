//1850
#include<iostream>
using namespace std;

int gcd(long a, long b);

int main() {

	long a, b;

	cin >> a >> b;
	long res = gcd(a, b);

	while (res > 0) {
		cout << "1";
		res--;
	}
	cout << endl;

}

int gcd(long a, long b) {	// 3 6
	if (b == 0) { //a가 최대공약수
		return a;
	}
	else {
		return gcd(b, a % b);	//최대공약수를 구하는 알고리즘
	}
}