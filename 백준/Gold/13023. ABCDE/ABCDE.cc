//13023 baekjoon
#include<iostream>
#include<vector>
using namespace std;

#define tmpNum 10

static vector<vector<int>> A;	//그래프 데이터 저장 인접 리스트 
static vector<bool> visited;
static int arrive;
void DFS(int now, int depth);	//DFS 함수

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;	//노드, 에지(간선)
	
	A.resize(N);
	visited = vector<bool>(N, false);

	for (int j = 0; j < M; j++) {
		int u, v;
		cin >> u >> v;

		A[u].push_back(v);
		A[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		DFS(i, 1);
		if (arrive) {
			break;
		}
	}

	//결과 출력
	if (arrive) {
		cout << arrive;
	}
	else { 
		cout << "0";
	}
}

void DFS(int now, int depth) {

	if (depth == 5 || arrive) {
		arrive = 1;
		return;
	}

	visited[now] = true;

	for (int i : A[now]) {
		if (!visited[i]) {
			DFS(i, depth + 1);
		}
	}

	visited[now] = false;

}