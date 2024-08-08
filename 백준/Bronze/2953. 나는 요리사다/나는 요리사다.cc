#include<iostream>
using namespace std;

int main() {
	int score[5][4];
	int totalScore[5] = { 0 };
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		for (int p = 0; p < 4; p++) {
			cin >> score[i][p];
			sum = sum + score[i][p];
			totalScore[i] = sum;
		}
		sum = 0;
	}

	int max = 0;

	for (int i = 1; i < 5; i++) {
		if (totalScore[max] < totalScore[i]) {
			max = i;
		}
	}

	cout << max + 1 <<" " << totalScore[max];
}