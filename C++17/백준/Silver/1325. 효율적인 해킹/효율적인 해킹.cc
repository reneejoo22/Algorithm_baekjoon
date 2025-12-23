// 1352
# include <iostream>
# include <vector>
# include <algorithm>
#include <queue>

using namespace std;

void BFS(int idx);
static vector<vector<int>>node;
static vector<int> answer;
static vector<bool> visited; // 이미 방문했던거는 빼기... 시간 복잡도 보는 방법 좀 길러야겠음....

int main() {
	int computerNum, relationshipNum;
	cin >> computerNum >> relationshipNum;

	node.resize(computerNum + 1); //이걸하는 이유?
	answer.resize(computerNum + 1); // 이거는 이해됨 컴퓨터가 노드가 양수일테니까. 이걸하면 자동으로 값이 0이 됨
	visited.resize(computerNum + 1);
	for (int i = 0; i < relationshipNum; i++) {
		int n, m;
		cin >> n >> m;
		node[n].push_back(m);
	}
	
	for (int i = 0; i <= computerNum; i++) {
		fill(visited.begin(), visited.end(), false);
		BFS(i);
	}
	
	int maxVal = 0;
	for (int i =0 ; i <= computerNum; i++) {
		maxVal = max(maxVal, answer[i]);
	}

	for (int i = 0; i <= computerNum; i++) {
		if (answer[i] == maxVal) {
			cout << i<< " ";
		}
	}
}

void BFS(int idx) { // 큐가 왜 필요한지 이해 못했고 - 큐가 있어야 bfs 방식으로 탐색 할 수 있음
	// 예를 들어서 a가 b,c 총 2개랑 연결되어있으면. 일단 b path로 쭉 가보고 그후 c path로 가도록...
	// 큐에 b,c를 저장하는것

	queue<int>q;
	q.push(idx);
	while (!q.empty()) {
		int now_node = q.front();
		visited[idx] = true;
		//cout << "now_node 는" << now_node<<endl;
		q.pop();
		for (int i : node[now_node]) {
			if (visited[i] == false) {
				visited[i] = true;
				//cout << "node[now_node] 존재해서 진입 " << now_node;
				//cout << " i 는" << i << endl;
				answer[i] += 1;
				q.push(i);
			}
		}
	}
	//cout << "큐 없음 나옴";
}