#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 506
#define INF 2e9

using namespace std;
int N;
int MAP[MAX][MAX];
pair<int, int> Start;
int moveY[4] = { 0,1,0,-1 };
int moveX[4] = { -1,0,1,0 };
/*
	서, 남, 동, 북쪽으로 이동할 때 모래가 흩날리는 방향 및 비율을 배열로 만들어준다.
*/
int spreadY[4][10] = { { -1,1,-1,1,-1,1,-2,2,0,0 }, 
					   { 0,0,1,1,2,2,1,1,3,2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 },
					   { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 } };
int spreadX[4][10] = { { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 },
					   { 0,0,1,1,2,2,1,1,3,2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 } };
int Sand_Percent[9] = { 1,1,7,7,10,10,2,2,5 };
int moveLen = 1; // 처음 이동 거리는 1
int Direction = 0; // 처음 이동 방향은 서쪽
int Dir_Change = 0; // 방향을 바꾼 횟수, 2번 바꿨다면 이동 거리를 1 증가시키고 횟수를 0으로 초기화
int answer = 0; // 격자 바깥으로 나간 모래의 양

void Sand_Spread(int Y, int X, int YY, int XX, int Sand, int Dir) {
	int tmp = Sand;
	for (int i = 0; i < 9; i++) { // α가 적혀있는 칸을 제외한 9방향으로 흩날린 모래의 양을 계산해준다.
		int nextY = Y + spreadY[Dir][i];
		int nextX = X + spreadX[Dir][i];
		int Per = Sand_Percent[i];
		int Sand_Part = (tmp * Per) / 100;
		// 모래가 격자 바깥으로 이동한 경우
		if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
			answer += Sand_Part;
		}
		else {
			MAP[nextY][nextX] += Sand_Part;
		}
		Sand -= Sand_Part;
		// 흩날린 모래의 양만큼 계속 빼주면 α가 적혀있는 칸으로 흩날릴 모래의 양만 남게 될 것이다.
	}
	int nextY = Y + spreadY[Dir][9];
	int nextX = X + spreadX[Dir][9];
	if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
		answer += Sand;
	}
	else {
		MAP[nextY][nextX] += Sand;
	}
	MAP[YY][XX] = 0; // 모래가 다 흩날리고 나면 Y 칸에 남은 모래는 0이 될 것이다.
}

void Tornado(int Y, int X, int Dir, int Len) {
	int CurY = Y;
	int CurX = X;
	for (int l = 0; l < Len; l++) {
		/*
			토네이도는 Len만큼 이동하면서 한 칸 이동할 때마다 모래가 흩날린다.
			이동하며 모래가 흩날린 후 토네이도의 현재 위치를 계속 초기화시켜준다.
		*/
		int nextY = CurY + moveY[Dir];
		int nextX = CurX + moveX[Dir];
		if (MAP[nextY][nextX] > 0) { 
			int Sand = MAP[nextY][nextX];
			Sand_Spread(CurY, CurX, nextY, nextX, Sand, Dir);
		}
		CurY = nextY;
		CurX = nextX;
	}
	// Dir 방향으로 Len만큼의 이동이 끝나면 다음 이동을 위해서 토네이도의 출발지점을 초기화한다.
	Start = make_pair(CurY, CurX);
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	// 시작은 무조건 가운데 지점에서부터 시작한다.
	Start = make_pair(N / 2, N / 2);
	while (1) {
		// 토네이도가 Direction 방향으로 moveLen만큼 이동 
		Tornado(Start.first, Start.second, Direction, moveLen);
		// 방향 전환(서 -> 남 -> 동 -> 북)
		Direction++; 
		if (Direction == 4) {
			Direction = 0;
		}
		// 방향이 2번 바뀔 때마다 토네이도의 이동 거리가 1씩 증가
		Dir_Change++;
		if (Dir_Change == 2) {
			Dir_Change = 0;
			moveLen++;
		}
		// 토네이도가 N만큼 이동하는 경우에는 토네이도가 (1, 1)까지 이동한 뒤 소멸한다는 뜻이다.
		if (moveLen == N) {
			Tornado(Start.first, Start.second, Direction, moveLen);
			break;
		}
	};

	cout << answer << "\n";

	return 0;
}