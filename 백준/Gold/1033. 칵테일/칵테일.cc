//1033
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

vector<tuple<int, int, int>>A[10];
long lcm;	//초기 최소공배수
bool visited[10];
long D[10];
long gcd(long a, long b);
void DFS(int node);

int main() {

	int N;	//재료의 갯수 N개 // N-1개 재료의 비율
	cin >> N;
	lcm = 1;

	for (int i = 0; i < N - 1; i++) {	
		//abpq_ a와b는 재료의 인덱스 값/ a의 질량:p / b의 질량:q
		int a, b, p, q;
		cin >> a >> b >> p >> q;	//4 0 1 1/ 4 1 3 1/ 4 2 5 1/ 4 3 7 1

		A[a].push_back(make_tuple(b, p, q)); // a 재료에서 b 재료로 가는 비율 저장
		A[b].push_back(make_tuple(a, q, p)); // b 재료에서 a 재료로 가는 반대 비율 저장

		/*
		재료 0과 재료 4는 질량 비율이 1:1입니다.
		재료 1과 재료 4는 질량 비율이 3:1입니다.
		재료 2와 재료 4는 질량 비율이 5:1입니다.
		재료 3과 재료 4는 질량 비율이 7:1입니다.
		*/
		//비율이. 1:1, 1:3, 1:5, 1:7임. 하나의 완성된 recipe 통합본을 알기 위해서는
		//최소공배수 값이 필요함

		lcm *= (p * q / gcd(p, q));	// 최소공배수_1,3,15,105
	}

	D[0] = lcm; // 첫 번째 재료의 질량을 최소 공배수(lcm)로 설정_105
	DFS(0);  // 첫 번째 재료부터 DFS 탐색 시작
	long mgcd = D[0];

	for (int i = 1; i < N; i++) {
		mgcd = gcd(mgcd, D[i]); // 모든 질량 값의 최대 공약수를 계산
	}
	for (int i = 0; i < N; i++) {
		cout << D[i] / mgcd << ' '; // 최대 공약수로 나눈 정규화된 질량 출력
	}
}

long gcd(long a, long b) {	//최소공배수
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

void DFS(int node) {
	visited[node] = true;

	for (tuple<int, int, int>i : A[node]) {
		int next = get<0>(i); // 다음 연결된 재료_4
		if (!visited[next]) {	//4번부터 방문
			// 현재 노드의 질량에 비례하여 다음 재료의 질량을 계산
			D[next] = D[node] * get<2>(i) / get<1>(i);	
			/*
			D[0] = 105
			4번 재료와 연결된 재료들을 탐색:
			4번 재료는 0번, 1번, 2번, 3번 재료와 연결되어 있습니다.

			1번 재료와 비율 3:1:
			D[1] = D[4] * 1 / 3 = 105 * 1 / 3 = 35

			2번 재료와 비율 5:1:
			D[2] = D[4] * 1 / 5 = 105 * 1 / 5 = 21

			3번 재료와 비율 7:1:
			D[3] = D[4] * 1 / 7 = 105 * 1 / 7 = 15
			*/
			DFS(next);
		}
	}
}