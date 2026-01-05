// 17144
# include <iostream>
# include <vector>
# include <algorithm>
#include <queue>

using namespace std;

int r, c, t;
int room[50][50];
int add[50][50];
int dr[4] = { -0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int up_row, down_row; //공기청정기 위치
int total_dust;


// 입력
void input() {
	cin >> r >> c >> t;

	bool flag = false;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> room[i][j];

			if (room[i][j] == -1) {
				if (!flag) {
					up_row = i;
					flag = true;
				}
				else {
					down_row = i;
				}
			}
			else {
				total_dust += room[i][j];
			}
		}
	}

}

void spread_dust() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int cnt = 0;
			int val = room[i][j] / 5;

			if (room[i][j] == -1 || room[i][j] == 0) continue;
			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nd = j + dc[k];

				// 1. 넘어가면 안됨
				if (nr < 0 || nr >= r || nd < 0 || nd >= c) continue;
				// 2. 공청기 있는 곳은 확산 안됨
				if (room[nr][nd] == -1) continue;
				// 3. 확산
				add[nr][nd] += val;
				cnt++;
			}
			add[i][j] -= (val * cnt);
		}
	}

	// 1초마다 확산... 업데이트
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {

			room[i][j] += add[i][j];
			add[i][j] = 0;
		}
	}
}

// 공기천정기 윗공기, 아랫공기
// 바람이 불면 미세먼지가 바람의 방향대로 모두 한 칸씩 이동한다.
void air_clean() {
	//사라지는 먼지 계산??
	total_dust -= room[up_row - 1][0]; //아 들어가는 먼지는 제거되기 때문
	total_dust -= room[down_row + 1][0];

	//위의 공기 반시계
	// 1. 왼쪽줄
	for (int i = up_row - 1; i > 0; i--)
		room[i][0] = room[i - 1][0];
	// 2. 윗줄
	for (int i = 0; i < c - 1; i++)
		room[0][i] = room[0][i + 1];
	// 3. 오른쪽줄
	for (int i = 1; i <= up_row; i++)
		room[i - 1][c - 1] = room[i][c - 1];
	// 4. 아랫줄
	for (int i = c - 1; i > 1; i--)
		room[up_row][i] = room[up_row][i - 1];
	room[up_row][1] = 0;

	// 아래공기 순환 (시계)
	// 1. 왼쪽줄
	for (int i = down_row + 1; i < r - 1; i++)
		room[i][0] = room[i + 1][0];
	// 2. 아랫줄
	for (int i = 0; i < c - 1; i++)
		room[r - 1][i] = room[r - 1][i + 1];
	// 3. 오른쪽줄
	for (int i = r - 1; i >= down_row; i--)
		room[i][c - 1] = room[i - 1][c - 1];
	// 4. 윗줄
	for (int i = c - 1; i > 1; i--)
		room[down_row][i] = room[down_row][i - 1];
	room[down_row][1] = 0;
}

void solve() {

	while (t--) {
		spread_dust();
		air_clean();
	}
	cout << total_dust << endl;
}

int main() {

	input();
	solve();
	return 0;
}