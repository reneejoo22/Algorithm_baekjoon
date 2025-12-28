// 16236
#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
pair<int, int>sharkPos;
int sharkSize = 2;
int ate = 0, ans = 0;
int map[25][25], visited[25][25];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int bfs();

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkPos = { i,j };
				map[i][j] = 0;
			}
		}
	}

	while (1) {
		int sec = bfs();
		ans += sec;
		if (sec == 0)
			break;
	}
	cout << ans << endl;
}

int bfs() {
	for (int i = 0; i < n; i++) {
		memset(visited[i], 0, sizeof(int)* n);  //? memset 방법 익히기
 	}

	int dist = 0; //거리
	queue<pair<int, int>>q; //상어의 이동 경로를 저장한 큐

	// 물고기를 먹은 길을 저장할 곳 필요  // ? pq 이거 익히기
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	q.push({ sharkPos.first, sharkPos.second }); //? 이거 큐에 넣어야
	visited[sharkPos.first][sharkPos.second] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visited[y][x] == dist) { //? 최단거리에 있는 물고기를 다 찾았을 때
			break;
		}
		for (int i = 0; i < 4; i++) {
			int moveY = y + dy[i];
			int moveX = x + dx[i];

			// 가장 먼저 맵 벗어났는지 확인
			if (moveY < 0 || moveY >= n || moveX < 0 || moveX >= n)
				continue;
			if (visited[moveY][moveX]) // 0 이 아니면
				continue;
			//지나갈 수 잇는 길이면 큐에 저장
			if (map[moveY][moveX] == sharkSize || map[moveY][moveX] == 0) {
				q.push({ moveY, moveX });
				visited[moveY][moveX] = visited[y][x] + 1;
			}
			// 먹을 수 있는 물고기라면
			else if (map[moveY][moveX] < sharkSize) {
				if (dist == 0)
					ate++; // 거리가 확정났다면 먹은 개수를 늘리지 않음
				visited[moveY][moveX] = visited[y][x] + 1;
				dist = visited[moveY][moveX];
				pq.push({ moveY, moveX });
			}
		}
	}

	if (pq.empty()) {
		return 0;
	}
	sharkPos.first = pq.top().first;
	sharkPos.second = pq.top().second;
	map[sharkPos.first][sharkPos.second] = 0;
	if (ate == sharkSize) {
		sharkSize++;
		ate = 0;
	}
	return visited[sharkPos.first][sharkPos.second] - 1;

}