//11508
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int A,a,B,b,P;
	cin >> A>>a>>B>>b>>P;
	bool possible = false;

	if (A + B <= P)
		possible = true;
	else if (a >= B && P >= A)
		possible = true;
	else if (A <= b && P >= B)
		possible = true;

	if (possible) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}
