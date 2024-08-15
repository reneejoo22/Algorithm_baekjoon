//5565
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int totalSum;
	cin >> totalSum;

	int price, sum = 0;

	for (int i = 0; i < 9; i++) {
		cin >> price;
		sum = sum + price;
	}

	cout << totalSum - sum;
}