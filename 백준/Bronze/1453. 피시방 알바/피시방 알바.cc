//1453
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<bool>A(101, true);
	int count = 0, num;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (!A[num]) {	//false 면
			count += 1;
		}
		else {	//true면
			A[num] = false;
		}
	}

	cout << count;
}
