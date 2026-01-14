// 16236
#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, ans = 0;
int sharkSize = 2, sharkX, sharkY, ate;
int map[20][20], visited[20][20];
int dy[4] = { -1,0,0,1 }, dx[4] = { 0,-1,1,0 };

int bfs() {
	for (int i = 0; i < n; i++) {
		memset(visited[i], 0, sizeof(int) * n);
	}
	int dist = 0;
	queue<pair<int, int>>q;//상어의 이동 경로를 저장한 큐
	//상어가 먹을 수 있는 물고기 위치, pq에는 물고기까지의 거리가 최단 거리인 것만 들어감
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	q.push({ sharkY,sharkX });  //상어 현재 위치
	visited[sharkY][sharkX] = 1;  // 현재 서있으니 방문한 것
	
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (visited[y][x] == dist)
			break;
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];  //상하좌우 탐색. 현재 위치에서
			int nx = x + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) //벗어난 경우
				continue;  //다음 반복문
			if (visited[ny][nx]) //방문한 경우
				continue; // 다음 반복문ㄴ
			if (!map[ny][nx] || map[ny][nx] == sharkSize) {
				// 자신과 같거나 0이면 지나갈 수 있음
				q.push({ ny,nx }); //나중에 지나가게 저장
				visited[ny][nx] = visited[y][x] + 1; //현재 자리에 2 기록. 시간
			}
			else if (map[ny][nx] < sharkSize) {
				//먹을 수 있음
				if (!dist)
					ate++;
				visited[ny][nx] = visited[y][x] + 1; //현재 자리에 2 기록. 시간
				dist = visited[ny][nx]; //최소 거리 확정
				pq.push({ ny,nx }); // 물고기를 먹은 좌표 저장!!!@
			}
		}
	}
	if (pq.empty()) {
		return 0;
	}
	sharkX = pq.top().second;
	sharkY = pq.top().first;

	map[sharkY][sharkX] = 0;
	if (ate == sharkSize) {
		sharkSize++;
		ate = 0;
	}
	return visited[sharkY][sharkX] - 1;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sharkX = j;
				sharkY = i;
				map[i][j] = 0; //이동할 수 있도록
			}
		}
	}

	while (1) {
		int sec = bfs();
		ans += sec;
		if (!sec) {
			break;
		}
	}
	cout << ans;
}

int main() {
	solve();
}

