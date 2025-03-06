//3109
#include <iostream>
using namespace std;

int dn[3] = { -1,0,1 };  //아래 가만 위
int du[3] = { 1,1,1 };  // 대각선 옆 대각선
int D, U = 0;
long long cnt = 0;
int map[10001][501];

void insert() {	

	cin >> D >> U;

	string in;
	for (int i = 0;i < D;i++) {
		cin >> in;
		for (int p = 0;p < U;p++) {
			if (in[p] == '.') map[i][p] = 0;
			else map[i][p] = 1;
		}
	}
}

bool dfs(int d, int u) {
	if (u == U - 1) {
		cnt++;
		return true;
	}

	map[d][u] = 1;

	for (int i = 0;i < 3;i++) {
		int nd = d + dn[i];     //(0,0) -> (-1,1) -> (0,1) -> (1,1)
		int nu = u + du[i];	   //(1,0)-> (0,1)-> (1,1)-> (2,1)

		if (nd >= 0 && nu >= 0 && nd < D && nu < U && !map[nd][nu]) {

			if (dfs(nd, nu)) return true;  //여길 만나면 종료
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	insert();

	//cout << "\n시작\n";
	for (int i = 0;i < D;i++) {
		//cout << i << endl;

		dfs(i, 0);
		/*
		for (int i = 0;i < D;i++) {
			for (int p = 0;p < U;p++) {
				cout << map[i][p];
			}
			cout << "\n";
		}
		cout << "cnt_" << cnt << endl;
	*/
	}

	cout << cnt;

}

