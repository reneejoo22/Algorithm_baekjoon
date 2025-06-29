#include <iostream>
using namespace std;

int T;
int R, C;
string board[400];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int ans = 0;
		cin >> R >> C;
		for (int r = 0; r < R; r++) cin >> board[r];

		for (int r = 0; r < R; r++) {
			for (int c = 0; c + 2 < C; c++) {
				if (board[r][c] == '>' && board[r][c + 1] == 'o' && board[r][c + 2] == '<') ans++;
			}
		}

		for (int c = 0; c < C; c++) {
			for (int r = 0; r + 2 < R; r++) {
				if (board[r][c] == 'v' && board[r + 1][c] == 'o' && board[r + 2][c] == '^') ans++;
			}
		}

		cout << ans << '\n';
	}
}