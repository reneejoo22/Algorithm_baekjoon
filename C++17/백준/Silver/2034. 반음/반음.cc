#include <iostream>

using namespace std;

int n;
int arr[10001];
char piano[12] = { 'C', 'X', 'D', 'X', 'E', 'F', 'X', 'G', 'X', 'A', 'X', 'B' };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) { 
		cin >> arr[i]; 
		arr[i] %= 12;
	}
	for (char c = 'A'; c <= 'G'; c++) {
		int idx;
		char last;
		for (int i = 0; i < 12; i++) {
			if (piano[i] == c) {
				idx = i;
				break;
			}
		}

		bool chk = true;
		for (int i = 0; i < n; i++) {
			idx += arr[i];
			idx %= 12;
			if (idx < 0) idx += 12;

			if (piano[idx] == 'X') {
				chk = false;
				break;
			}
			last = piano[idx];
		}
		if (chk) cout << c << ' ' << last << endl;
	}
}