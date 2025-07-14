#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<char>> arr(N);

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			arr[i].push_back(str[j]);
		}
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		char row = arr[i][0];
		count++;

		if (i > 0 && row == '|'&&row == arr[i - 1][0]) count--;

		for (int j = 1; j < M; j++) {
			if (row != arr[i][j]||(row==arr[i][j] && row=='|')) {
				count++;
				row = arr[i][j];
			}
			if (i > 0 && arr[i][j] == '|'&&arr[i][j] == arr[i - 1][j]) count--;
		}
	}

	cout << count;

	return 0;
}