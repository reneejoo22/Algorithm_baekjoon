// 2667
#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };
int map[25][25], visited[25][25];
int houseSize;
static vector<int>cntHouse;

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[nx][ny] && !visited[nx][ny]) {
			visited[nx][ny] = 1;
			houseSize++;
			dfs(nx, ny);
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !visited[i][j]) {
				visited[i][j] = 1;
				houseSize = 1;
				dfs(i, j);
				cntHouse.push_back(houseSize);
				// res가 있는데 그냥 벡터 크기를 써도 될것 같음.
			}
		}
	}

	sort(cntHouse.begin(), cntHouse.end());
	cout << cntHouse.size()<<endl;
	for (int i = 0; i < cntHouse.size(); i++) {
		cout << cntHouse[i]<<endl;
	}
	return;
}

void input() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			if (tmp[j] == '0') {
				map[i][j] = 0;
			}
			else {
				map[i][j] = 1;
			}
		}
	}
}

int main() {
	input();
	solve();
}