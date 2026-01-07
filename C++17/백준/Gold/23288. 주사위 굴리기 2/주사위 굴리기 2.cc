// 23288
#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;  //이동횟수?
int map[22][22];
int visited[22][22];

int dice[7] = { 0,1,2,3,4,5,6 };
int dy[4] = {0,1,0,-1}; // 동 남 서 북
int dx[4] = { 1,0,-1,0 };


void input() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
}


void move(int d) {  //덮어씌워지지  않도록 조심
	int tmp[7];
	for (int i = 1; i <= 6; i++) {  // 윗면이 1, 아랫면이 6. 왼 4, 오3
		tmp[i] = dice[i];
	}
	if (d == 0) { //동
		dice[1] = tmp[4];
		dice[3] = tmp[1];
		dice[4] = tmp[6];
		dice[6] = tmp[3];
	}
	else if (d == 1) { //남
		dice[1] = tmp[2];
		dice[2] = tmp[6];
		dice[5] = tmp[1];
		dice[6] = tmp[5];
	}
	else if (d == 2) {  //서
		dice[1] = tmp[3];
		dice[4] = tmp[1];
		dice[3] = tmp[6];
		dice[6] = tmp[4];
	}
	else { //북
		dice[1] = tmp[5];  //기준이 되는 것 먼저
		dice[2] = tmp[1]; // 위
		dice[5] = tmp[6]; // 아래
		dice[6] = tmp[2]; //마주보는 것 마지막에
	}
}

int dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (map[ny][nx] && map[ny][nx] == map[y][x] && !visited[ny][nx]) {  //범위 밖이 아니고 같은 숫자고 아직 안간칸
			ret += dfs(ny, nx); // 연결된 같은 숫자 칸을 계속 찾아가며
		}
	}
	return ret;
}

void solve() {

	int d = 0, fx = 1, fy = 1, ans = 0, cnt = 0; // 1,1에서 시작. 첫 방향은 동
	while (k--) {
		int nx = fx + dx[d];
		int ny = fy + dy[d];

		if (!map[ny][nx]) {
			d = (d + 2) % 4;   //값이 없으면, 못가면 반대방향
			k++;
			continue;
		}
		//값이 있으면 이동
		move(d);
		if (dice[6] > map[ny][nx]) d = (d + 1) % 4;  //오른
		else if(dice[6]<map[ny][nx]) d = (d + 3) % 4;  //왼
		ans += dfs(ny, nx) * map[ny][nx];
		memset(visited, 0, sizeof(visited));
		fy = ny, fx = nx;
	}
	cout << ans << endl;
}

int main() {
	input();
	solve();
}