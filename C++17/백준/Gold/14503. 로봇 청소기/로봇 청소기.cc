// 14503
# include <iostream>

using namespace std;

int map[50][50];
bool visited[50][50] = { false };
int visited_count = 0;

// 북동남서, 아래 오른 위 왼
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;
int x, y, d;

void input() {
	cin >> n >> m;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	visited[x][y] = true;
	// 있는 자리는 무조건 청소
	visited_count++;
}

void dfs() {

	for (int i = 0; i < 4; i++) {
		int nextD = (d + 3 - i) % 4;  // 왼쪽
		int nextX = x + dx[nextD];
		int nextY = y + dy[nextD];

		if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || map[nextX][nextY] == 1) continue;
		if (map[nextX][nextY] == 0 && visited[nextX][nextY] == false) {
			visited[nextX][nextY] = true;
			x = nextX;
			y = nextY;
			d = nextD;
			visited_count++;
			dfs();  //그럼곗ㄱ 왼왼왼 가다가 갈곳없으면 후진?
		}
	}

	int back_idx = d > 1 ? d - 2 : d + 2; //방향 유지한채 후진
	int backX = x + dx[back_idx];
	int backY = y + dy[back_idx];

	if (backX >= 0 || backX < n || backY >= 0 || backY < m) {
		if (map[backX][backY] != 1) {
			x = backX;
			y = backY; //후진
			dfs();  //근데 그러면  위에 반복문을 또 하는거? 어차피 visited했으니가 상관없나?..
		}
		else {
			cout << visited_count << endl;
			exit(0);
		}
	}
	
}
int main() {
	input();
	dfs();
	return 0;
}


