#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>A;
	vector<int>S; int score = 0; int totalScore = 0;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.insert(A.begin() + i, num);

		if (num == 1) {
			S.insert(S.begin() + i, score = score + 1);
		}
		else {
			score = 0;
			S.insert(S.begin() + i, score);
		}

		totalScore = totalScore + S[i];
	}

	cout << totalScore;

}