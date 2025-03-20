//15903
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m; //카드갯수, 합체수
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>>pq;  // greater 가 오름차순
	for (int i = 0;i < n;i++) {
		long long num;
		cin >> num;
		pq.push(num);
	}

	long long tmp;
	long long sum = 0;
	while (m--) {
		tmp = pq.top();
		pq.pop();
		tmp += pq.top();
		pq.pop();
		pq.push(tmp); // cout << tmp<<endl;
		pq.push(tmp);
	}

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum;
}

// segment fault_잘못된 메모리를 참조한 후 그 메모리를 해제할 때 발생한다고 한다.

/*
1 2 3 4
3 3 3 4
3 4 6 6
이렇게 동작...

*/