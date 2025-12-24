// 1707
# include <iostream>
# include <vector>
# include <algorithm>
#include <queue>

using namespace std;

static vector<vector<int>>node;
static vector<bool>visited;
static vector<int>check;
static bool isEven;
void DFS(int startNode);

int main() {
	int testCaseNum;
	cin >> testCaseNum;

	for (int i = 0; i < testCaseNum; i++) {
		int nodeNum, edgeNum;
		cin >> nodeNum >> edgeNum;

		node.resize(nodeNum + 1);
		visited.resize(nodeNum + 1);
		check.resize(nodeNum + 1);
		isEven = true;

		for (int j = 0; j < edgeNum; j++) {
			int v, e;
			cin >> v >> e;
			node[v].push_back(e);
			node[e].push_back(v);
		}
		for (int p = 1; p <= nodeNum; p++) {
			if (isEven) {
				// cout << p << " 넣어서 dfs 호출" << endl;
				DFS(p);
			}
			else {
				break;
			}
		}
		if (isEven) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		for (int i = 0; i <= nodeNum; i++) {
			node[i].clear();
			visited[i] = false;
			check[i] = 0;
		}
	}
	
}

void DFS(int startNode) {
	// cout << startNode <<" DFS 시작" << endl;
	visited[startNode] = true;

	for (int i : node[startNode]) {
		if (!visited[i]) {  //방문하지 않았다면 
			check[i] = (check[startNode] + 1) % 2;
			// cout <<"i는 " << i << "check[i] = " << check[i]<<endl;
			DFS(i);  // 아 이게 deep fs 방식이 맞음... 예를 들어 startNode가 1이고 2,3이있음. 그러면
			// 2에다가 check 하고... startNode를 2로 줘서 다시 시작
		}
		
		// 깊이 탐색 계속 하다가 전에 방문했던걸 만났을때(문제는 안되지만)
		// 문제는 같은 그룹일 때 사이클. check는 “어느 편이냐”를 알려준다.
		else if (check[startNode] == check[i]) {
			// cout << startNode <<" and "<<i<<" is same to "<<check[startNode] << "so lead to even false" << endl;
			isEven = false;
		}
		// cout << i << " 방문했던거!" << endl;
	}
	// cout << startNode << "DFS 종료" << endl;
}

/*
2
3 2
(1-2-3 예시)
1 2
2 3
1 넣어서 dfs 호출
1 DFS 시작
i는 2check[i] = 1
2 DFS 시작
i는 3check[i] = 0
3 DFS 시작
3DFS 종료
2DFS 종료
1DFS 종료
2 넣어서 dfs 호출
2 DFS 시작
2DFS 종료
3 넣어서 dfs 호출
3 DFS 시작
3DFS 종료
YES
3 3
(1-2-3-1 예시)
1 2
2 3
3 1
1 넣어서 dfs 호출
1 DFS 시작
i는 2check[i] = 1
2 DFS 시작
i는 3check[i] = 0
3 DFS 시작
3 and 1 is same to 0so lead to even false
3DFS 종료
2DFS 종료
1 and 3 is same to 0so lead to even false
1DFS 종료
NO
*/