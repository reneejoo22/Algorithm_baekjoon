// 14503
# include <iostream>

using namespace std;
#define max 50
int n, m;
int visited_count;
int map[max][max];
int visited[max][max] = { 0 };

// 북동남서
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int x, y, d;

void input() {
	cin >> n >> m; //맵 상태
	cin >> x >> y >> d; // 청소기 좌표, 방향

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j]; 
		}
	}

	visited[x][y] = 1; //청소기가 있는 자리
	visited_count++;   //있는 자리는 방문 한 것. 얘가 청소한 횟수. 맵은 어차피 청소 or 벽임
}

void dfs() {
	for (int i = 0; i < 4; i++) {
		int nextD = (d + 3 - i) % 4; //왼쪽으로 90도
		int nextX = x + dx[nextD]; //어쩐지 방향을 활용을 안했더라...
		int nextY = y + dy[nextD];

		// 1. 넘는지 아닌지
		if (nextY >= m || nextY < 0 || nextX >= n || nextX < 0 || map[nextX][nextY] == 1) continue;

		//2. 갈 수 있다면
		if (map[nextX][nextY] == 0 && visited[nextX][nextY] == 0) {
			visited[nextX][nextY] = 1;
			x = nextX;
			y = nextY;
			d = nextD;
			visited_count++;
			dfs(); //깊이니까 일단 북북북 이동했다가 끝을 본뒤 동북북...더보기
		}
	}

	int back_idx = d > 1 ? d - 2 : d + 2; //서쪽이나 남쪽을 보고 있으면 동북을 보도록... 180 도 회전...
	int back_x = x + dx[back_idx];
	int back_y = y + dy[back_idx];
	// 3. 4 방향 모두 청소가 되어있는 경우 or 벽인 경우... 후진?
	if (back_x >= 0 && back_x < n && back_y >= 0 && back_y < m) {

		// 바라보는 방향을 유지한채 후진...
		if (map[back_x][back_y] == 0) {
			x = back_x;
			y = back_y;
			dfs();
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