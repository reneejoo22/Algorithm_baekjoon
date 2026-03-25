#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_NUM 105

//(0,0) x → → →
//y
//↓
//↓
// 우 상 좌 하
int dx[4] = {1,0,-1,0};  
int dy[4] = {0,-1,0,1}; 
// map[y][x]

int main() {
	int n, k;
	int map[MAX_NUM][MAX_NUM] = {0};
	int visited[MAX_NUM][MAX_NUM] = { false };
	int x = 1, y = 1, dir = 0;
	queue<pair<int, int>>q;  // 몸 좌표
	q.push(make_pair( x,y ));
	
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int y,x;
		cin >> y >> x;
		map[y][x] = 1;
	}

	int l;
	cin >> l;
	int ans = 0;
	for (int i = 0; i < l; i++) {
		int time;
		char char_dir;
		cin >> time >> char_dir;

		while (ans < time || i == l - 1) {
			//마지막 입력까지 게임이 끝나지 않을 경우 뱀을 끝날때까지 보내줘야함
			ans++;
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (nx >= 1 && ny >= 1 && ny <= n && nx <= n && !visited[ny][nx]) {
				//게임이 끝나지 않는 조건
				if (map[ny][nx] == 1) { //사과가 있다면
					map[ny][nx] = 0;
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
				else {  // 사과가 없을 때
					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
					visited[q.front().first][q.front().second] = false;
					q.pop();
				}
			}
			else {
				cout << ans;
				return 0;
			}
			x = nx;
			y = ny;
			if (ans == time) {
				if (char_dir == 'L')dir = (dir + 1) % 4;
				else {
					dir = (dir + 3) % 4;
				}
			}
		}
	}
	return 0;
}
