//11724 baekjoon
#include<iostream>
#include<vector>
using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;	//방문 저장 기록 배열
void DFS(int v);	//그래프 데이터 저장 인접 리스트

int main() {
	
	int N, M;	//노드, 에지(선)
	cin >> N >> M;
	A.resize(N + 1);
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {	//인접 리스트 A에 그래프 데이터 저장
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}

	int count = 0;

	for (int i = 1; i < N + 1; i++) {
		if (!visited[i]) { //방문하지 않은 노드가 없을 때까지 반복
			count++;
			DFS(i);
		}
	}

	cout << count << "\n";

}

void DFS(int v){

	if (visited[v]) {
		return;
	}

	visited[v] = true;

	for (int i : A[v]) {
		if (visited[i] == false) {	//연결 노드 중 방문하지 않은 노드만 탐색함
			DFS(i);
		}
	}

}