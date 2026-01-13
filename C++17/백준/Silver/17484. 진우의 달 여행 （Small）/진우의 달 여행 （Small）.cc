// 17144
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

const int INF = 2137000000;
int dx[3] = { -1, 0, 1 };
int n, m;
int map[7][7];
int ans = INF;

int move(int y, int x, int last) {
	if (y == n)return 0;
	int ret = INF;

	for (int i = 0; i < 3; i++) {
		if (last == i) continue; //ㄱ같은 방향으로 연속 이동 안되기 때문에
		int nextX = x + dx[i];
		
		if (nextX < 0 || nextX >= m)continue;
		// cout << i << " i, curr "<<map[y+1][nextX] << endl;
		ret = min(ret, move(y + 1, nextX, i)+ map[y][x]);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		ans= min(ans,move(0,i,-1));
	}
	cout << ans << endl;
}
