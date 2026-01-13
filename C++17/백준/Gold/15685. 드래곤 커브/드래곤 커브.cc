// 15685
#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

#define MAX 101
int n;
int x, y, d, g, cnt;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<int>direction;
int map[MAX][MAX];

void makeDragon() {
	int size = direction.size() - 1;
	for (int i = size; i >= 0; i--) {
		int tmpD = (direction.at(i) + 1) % 4;
		x += dx[tmpD];
		y += dy[tmpD];
		map[x][y] = 1;
		direction.push_back(tmpD);
	}
}

void countSquare() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] && map[i + 1][j] && map[i + 1][j + 1] && map[i][j + 1])cnt++;
		}
	}
}

int main() {
	cin >> n;
	while (n--) {
		direction.clear();
		cin >> x >> y >> d >> g;

		map[x][y] = 1;

		// 1 generaion
		x += dx[d];
		y += dy[d];
		map[x][y] = 1;
		direction.push_back(d);

		while (g--) {
			makeDragon();
		}
	}
	countSquare();
	cout << cnt<<endl;
}