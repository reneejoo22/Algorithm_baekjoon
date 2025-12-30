// 14499
#include<iostream>
#include<vector>

using namespace std;
// 세로 , 가로,   x,  y, 
int col, row, diceX, diceY, order;
int moveOrder[1000];
int map[20][20];
int dice[6];
bool judgement(int target);
void diceMove(int d);
void diceRoll();

int main() {
	cin>> col >> row >> diceX >> diceY >> order;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < order; i++) {
		cin >> moveOrder[i];
	}

	diceRoll();
}

// 벗어나지 않게
bool judgement(int target) {  // 동 1_서 2_북 3_남 4
	if (target == 1) {
		if (diceY == row - 1) return false;
	}
	else if (target == 2) {
		if (diceY == 0)return false;
	}
	else if (target == 3) {
		if (diceX == 0)return false;
	}
	else if (target == 4) {
		if (diceX == col - 1)return false;
	}
	return true;
}

// 순차적으로... 값이 덮이지 않게 조심
void diceMove(int d) {
	//dice[6] = { 위, 아래, 동, 서, 남, 북 };
	int tmp = dice[0]; // 위
	if (d == 1) { //동
		diceY++;
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
	}
	else if (d == 2) { //서
		diceY--;
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
	}
	else if (d == 3) { //북
		diceX--;
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
	}
	else if (d == 4) { //남
		diceX++;
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
	}
}

void diceRoll() {
	for (int i = 0; i < order; i++) {
		if (!judgement(moveOrder[i])) {
			continue;
		}

		diceMove(moveOrder[i]);
		if (map[diceX][diceY] == 0) {
			map[diceX][diceY] = dice[1]; //지도 칸이 0이면 주사위 아랫면을 복사
		}
		else {
			dice[1] = map[diceX][diceY];
			map[diceX][diceY] = 0;
		}
		cout << dice[0] << endl;
	}
};