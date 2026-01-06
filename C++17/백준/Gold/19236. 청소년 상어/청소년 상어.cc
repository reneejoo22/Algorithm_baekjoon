# include <iostream>
#include <vector>

#define max 4
using namespace std;

int ans = 0;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }; //8 방향
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

struct Fish {
	int x = 0;
	int y = 0;
	int d = 0;
	int num = 0;
	bool alive = true;
};

static vector<vector<int>> v(4, vector<int>(4));
static Fish fish[16];

void input() {
	for (int i = 0; i < max; i++) {
		for (int j = 0; j < max; j++) {
			int num, dir;
			cin >> num >> dir;
			num--; dir--; //이거 왜 하는거?-이해
			v[i][j] = num;  //인덱스가 물고기 번호
			fish[num].x = i;
			fish[num].y = j;
			fish[num].d = dir;
			fish[num].num = num + 1; // 점수 계산용
		}
	}
}

void stimulate(vector<vector<int>>&v, Fish* fish, int sharkX, int sharkY, int sum) {
	vector<vector<int>> cpv(4, vector<int>(4));
	Fish cpFish[16];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cpv[i][j] = v[i][j];
		}
	}
	for (int i = 0; i < 16; i++) {
		cpFish[i] = fish[i];
	}

	// 상어가 물고기 먹음
	int n = cpv[sharkX][sharkY];
	cpv[sharkX][sharkY] = -1;
	cpFish[n].alive = false;
	sum += cpFish[n].num;

	if (ans < sum)ans = sum;

	// 물고기 이동
	for (int i = 0; i < 16; i++) {
		if (cpFish[i].alive) {
			int x = cpFish[i].x;
			int y = cpFish[i].y;
			int d = cpFish[i].d;

			int nextX = x + (dx[d % 8]); //왜 그냥 d가 아니지?
			int nextY = y + (dy[d % 8]); //왜 그냥 d가 아니지

			// 1. 넘어가는 경우
			while (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4 || (sharkX == nextX && sharkY == nextY)) {
				d++; //아... 이것 때문에 자칫하면 8을 넘어갈 수 있음.
				nextX = x + (dx[d % 8]); //왜 그냥 d가 아니지
				nextY = y + (dy[d % 8]); //왜 그냥 d가 아니지
			}

			if (cpv[nextX][nextY] != -1) { //어차피 살아있음
				int swapfish = cpv[nextX][nextY];
				cpFish[i].x = nextX; //이 3개는 지금 자리에 다른 물고기 정보 넣기.
				cpFish[i].y = nextY;
				cpFish[i].d = d;
				cpFish[swapfish].x = x;
				cpFish[swapfish].y = y; //num은 안 바꾸나?...i가 정체성, num이 점수?
				// 어차피 이동했으니 d 정보는 필요없

				cpv[nextX][nextY] = i;
				cpv[x][y] = swapfish;
			}
			else {
				cpFish[i].x = nextX;
				cpFish[i].y = nextY;
				cpFish[i].d = d;
				cpv[nextX][nextY] = i;
				cpv[x][y] = -1;
			}
		}
	}
	//먹고 방향 결정
	int sharkD = cpFish[n].d;
	// 상어 이동
	for (int i = 1; i < 4; i++) {
		int dirx = dx[sharkD % 8] * i; //왜 곱하지? - 거리만큼 이동하기에
		int diry = dy[sharkD % 8] * i;
		int nextX = sharkX + dirx;
		int nextY = sharkY + diry;

		if (nextX < 0 || nextX >= 4 || nextY < 0 || nextY >= 4) break;
		if (cpv[nextX][nextY] != -1)
			stimulate(cpv, cpFish, nextX, nextY, sum);
	}
}
int main() {

	input();
	stimulate(v, fish, 0, 0, 0);
	cout << ans << endl;
	return 0;
}