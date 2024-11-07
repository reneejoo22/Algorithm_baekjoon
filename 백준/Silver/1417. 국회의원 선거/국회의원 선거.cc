#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, dasom;
	priority_queue<int>A;
	cin >> n;
	cin >> dasom;

	n--;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp >= dasom) {
			A.push(tmp);
		}
	}

	int t, ans = 0;	//잠시 저장. ans는 출력할 값
	while (!A.empty() && dasom <= A.top()) {
		
		t = A.top();A.pop();
		t--; ans++; dasom++;
		A.push(t);
	}

	cout << ans;
}