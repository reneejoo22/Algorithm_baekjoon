//1260 baekjoon
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

static vector<vector<int>>A;	//2차배열. 자동으로 메모리 관리,동적크기,복사
static vector<bool> visited;
static bool arrive;
void DFS(int v);
void BFS(int v);

int main() {
	int N, M, V;	//정점, 간선, 시작 정점
	arrive = false;
	cin >> N >> M >> V;
	
	A.resize(N + 1);	//정점의 갯수
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e); A[e].push_back(s);	//인접행렬
	}
	
	for (int i = 0; i <= N; i++) {	//번호가 작은 것을 먼저 방문하기위해
		sort(A[i].begin(), A[i].end());
	}

	DFS(V);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);	//초기화
	BFS(V);
}

void DFS(int v) {

	cout << v << " ";
	visited[v] = true;

	for (int i : A[v]) {
		if (!visited[i]) {
			DFS(i);
		}
	}
};

void BFS(int v) {
	queue<int> myqueue;
	myqueue.push(v);
	visited[v] = true;

	while (!myqueue.empty()) {
		int nowNode = myqueue.front();
		myqueue.pop();
		cout << nowNode << " ";
		for (int i : A[nowNode]) {	//행을 봄
			if (!visited[i]) {
				visited[i] = true;
				myqueue.push(i);	//
			}
		}
	}
};

/*
A[N+1][N+1]
0 1 2 3 4 5
  2 1
  3   1
  4     1
	4   2
	  4 3

queue
1 2 3 4

갈 곳 없으니i+1 = 2
근데 1은 방문했으니 넘김

i+1 = 3
근데 1과 4는 방문했으니 넘김

i+1 = 3
근데 1과 4는 방문했으니 넘김

i+1 = 4
근데 1과 2와 3은 방문했으니 넘김


visited[N+1]

0 1 2 3 4 5
  1
*/