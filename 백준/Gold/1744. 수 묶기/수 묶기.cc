//1744
#include<iostream>
#include<queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int>pq;  //양수_여기서 2개 더하고 나머지 곱셈_내림차순
	priority_queue<int, vector<int>, greater<int>>npq;  //음수_곱셈만_오름차순
	int one = 0, zero = 0;
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num > 1) {	//2,3,4,5
			pq.push(num);
		}
		else if(num == 1){	//1
			one++;
		}
		else if (num == 0) {	//0
			zero++;
		}
		else {	//-n
			npq.push(num);
		}
	}

	int data1, data2;
	int sum = 0;

	while (pq.size() > 1) {	//양수처리
		data1 = pq.top();
		pq.pop();
		data2 = pq.top();
		pq.pop();

		sum = sum + (data1 * data2);
	}
	if (!pq.empty()) {
		data1 = pq.top();
		pq.pop();
		sum += data1;
	}

	while (npq.size() > 1) {	//음수처리
		data1 = npq.top();
		npq.pop();
		data2 = npq.top();
		npq.pop();

		sum += data1 * data2;
	}
	if (!npq.empty()) {
		if (zero == 0) {	//0이 없으면 그냥 음수 그냥 더하고 아니면 아예 더하지 말기 
			//어차피 0 곱하면 더할 값 없으니까 신경 ㄴㄴ
			sum = sum + npq.top();
			npq.pop();
		}
	}

	sum = sum + one;
	cout << sum;
	return 0;
}