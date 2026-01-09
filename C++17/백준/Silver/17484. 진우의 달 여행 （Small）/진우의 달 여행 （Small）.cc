// 17144
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;

const int INF = 2137000000;
int dx[3] = { -1,0,1 };
int n, m, ans = INF, map[7][7];

int solve(int y, int x, int last) {
	if (y == n) return 0; //끝에 도달하면 이 path는 끝
	int ret = INF;  //끝에 도달한 후 뒤로 한발짝 가서 거기서 dx[1]로 감

	for (int i = 0; i < 3; i++) {
		if (last == i) continue;
		if (x + dx[i] < 0 || x + dx[i] >= m) continue;   //범위 안 벗어나게
		ret = min(ret, solve(y + 1, x + dx[i], i) + map[y][x]);
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
	for (int i = 0; i < m; i++) { //가로 길이만큼
		ans = min(ans, solve(0, i, -1));
	}

	cout << ans << endl;
	return 0;
}