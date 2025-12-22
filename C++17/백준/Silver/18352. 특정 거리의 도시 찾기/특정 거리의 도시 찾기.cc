# include <iostream>
# include <vector>
# include <algorithm>
#include <queue>

using namespace std;

void bfs(int x);
static vector<vector<int>>A;
static vector<int>visited;
static vector<int>ans;

int main() {
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	A.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		A[s].push_back(e);
	}
	visited.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		visited[i] = -1;
	}
	bfs(x);

	for (int i = 0; i <= n; i++) {
		if (visited[i] == k) {
			ans.push_back(i);
		}
	}
	if (ans.empty()) {
		cout << -1 << "\n";
	}
	else {
		sort(ans.begin(), ans.end());
		for (int tmp : ans) {
			cout << tmp << "\n";
		}
	}
}

void bfs(int x) {
	queue<int>q;
	q.push(x);
	visited[x]++;

	while (!q.empty()) {
		int now_node = q.front();
		q.pop();
		for (int i : A[now_node]) {
			if (visited[i] == -1) {  // 방문 안 했으면
				visited[i] = visited[now_node] + 1;  
				q.push(i);
			}
		}
	}
}