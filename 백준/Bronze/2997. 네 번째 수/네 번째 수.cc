//2997
#include<iostream>
#include<algorithm>
using namespace std;

#define numMax 3
int a[numMax], d1, d2;

int main() {
	

	for (int i = 0; i < numMax; i++) {
		cin >>a[i];
	}

	sort(a, a + numMax);

	d1 = a[1] - a[0];
	d2 = a[2] - a[1];

	if (d1 > d2) {
		cout << a[0] + d2;
	}
	else if (d1 == d2) {
		cout << a[2] + d1;
	}
	else cout << a[1] + d1;

}