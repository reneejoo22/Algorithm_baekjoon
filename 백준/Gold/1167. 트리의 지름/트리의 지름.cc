#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int>edge;
static vector<vector<edge>>A;
static vector <bool>visited;
static vector<int>m_distance;
void BFS(int node);

int main() {

	int N;
	cin >> N;
	A.resize(N + 1);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		while (true) {
			int e, v;

			cin >> e;
			if (e == -1) {
				break;
			}
			cin >> v;

			A[num].push_back(edge(e, v));
		}
	}

	m_distance = vector<int>(N + 1, 0);
	visited = vector<bool>(N + 1, false);

	BFS(1);
	int max = 1;

	for (int i = 2; i <= N; i++) {
		if (m_distance[max] < m_distance[i]) {
			max = i;
		}
	}

	fill(m_distance.begin(), m_distance.end(), 0);
	fill(visited.begin(), visited.end(), false);

	BFS(max);

	sort(m_distance.begin(), m_distance.end());

	cout << m_distance[N];

}


void BFS(int node) {

	queue<int>myqueue;	//앞으로 방문할 정점 리스트
	myqueue.push(node);
	visited[node] = true;

	while (!myqueue.empty()) {
		int now = myqueue.front();
		myqueue.pop();

		for (edge i : A[now]) {
			if (!visited[i.first]) {
				visited[i.first] = true;
				myqueue.push(i.first);

				m_distance[i.first] = i.second + m_distance[now];
			}
		}

	}
}


/*
예제
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1


BFS 돌리기 전 상태
A
0  1     2     3     4    5
  (3,2) (4,4) (1,2) (2,4) (4,6)
			  (4,3) (3,3)
					(5,6)

m_distance
0 1 2 3 4 5
0 0 0 0 0 0

visited
0 1 2 3 4 5
F F F F F F

=====================

BFS(1);

myqueue
1

visited
0 1 2 3 4 5
F T F F F F

------round1------

now = 1

A[1]행 edge 보기
(3,2) 여기서 i.first는 3

visited
0 1 2 3 4 5
F T F T F F

myqueue(다음에 방문할 곳)
3

m_distance
0 1 2 3 4 5
0 0 0 2 0 0

------round2------

now = 3

A[3]행 edge 보기
(1,2) 여기서 i.first는 1
(4,3) 여기서 i.first는 4

visited
0 1 2 3 4 5
F T F T T F

myqueue(다음에 방문할 곳)
4

m_distance
0 1 2 3 4 5
0 0 0 2 5 0

------round3------

now = 4

A[4]행 edge 보기
(2,4) 여기서 i.first는 2
(3,3) 여기서 i.first는 3
(5,6) 여기서 i.first는 5


visited
0 1 2 3 4 5
F T T T T F

myqueue(다음에 방문할 곳)
2

m_distance
0 1 2 3 4 5
0 0 9 2 5 0

===
A[4]행 edge 보기
(5,6) 여기서 i.first는 5

visited
0 1 2 3 4 5
F T T T T T

myqueue(다음에 방문할 곳)
2 5

m_distance
0 1 2 3 4 5
0 0 0 2 5 11

myqueue(다음에 방문할 곳)	이미 다 방문했으니 pop

------------round finish-------------

max = 5

m_distance
0 1 2 3 4 5
0 0 0 0 0 0

visited
0 1 2 3 4 5
F F F F F F

=====================

BFS(5)

myqueue
5

visited
0 1 2 3 4 5
F F F F F T

------round1------

now = 5

A[5]행 edge 보기
(4,6) 여기서 i.first는 4

visited
0 1 2 3 4 5
F F F F T T

myqueue(다음에 방문할 곳)
4

m_distance
0 1 2 3 4 5
0 0 0 0 6 0

------round2------

now = 4

A[4]행 edge 보기
(2,3) 여기서 i.first는 2
(3,3) 여기서 i.first는 3
(5,6) 여기서 i.first는 5

visited
0 1 2 3 4 5
F F T F T T

myqueue(다음에 방문할 곳)
2

m_distance
0 1 2 3 4 5
0 0 9 0 6 0

===

A[4]행 edge 보기
(3,3) 여기서 i.first는 3

visited
0 1 2 3 4 5
F F T T T T

myqueue(다음에 방문할 곳)
2 3

m_distance
0 1 2 3 4 5
0 0 9 9 6 0

------round3------

now = 2

A[2]행 edge 보기
(4,4) 여기서 i.first는 4

visited
0 1 2 3 4 5
F F T F T T

myqueue(다음에 방문할 곳)
3

m_distance
0 1 2 3 4 5
0 0 9 9 6 0

------round4------

now = 3

A[3]행 edge 보기
(1,2) 여기서 i.first는 1
(4,3) 여기서 i.first는 4

visited
0 1 2 3 4 5
F F T T T T

myqueue(다음에 방문할 곳)
1

m_distance
0 1  2 3 4 5
0 11 9 9 6 0

------round5------

now = 1

A[1]행 edge 보기
(3,2) 여기서 i.first는 3

visited
0 1 2 3 4 5
F T T T T T

------------round finish-------------

m_distance
0 1 2 3 4 5
0 0 6 9 9 11

m_distance[5] = 11

*/