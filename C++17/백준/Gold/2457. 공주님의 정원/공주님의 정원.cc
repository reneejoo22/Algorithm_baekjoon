//2457
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, res, cur{301};  //변수 선언하고 초기화, 리스트 아님
vector<int> v;

void Solve() {
	while (cur < 1201) {
		if (cur >= v[cur]) {  //종료 기간이 3월 1일 이하인것
			cout << 0 << '\n';
			return;
		}
		cur = v[cur]; //아니면 그냥 덮기
		res++;
		sort(v.begin(), v.begin() + cur + 1); // 다시 현재값부터 끝값까지
	}
	cout << res << '\n';
}

void Init() {
	cin >> N;
	v.resize(1232);
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a * 100 + b] = max(v[a * 100 + b], c * 100 + d);  //피는 날짜가 같은 경우 더 늦게 피는 값으로 바꾸기
	}
	sort(v.begin(), v.begin() + cur + 1);  //3월 1일 이하까지만 정렬... 여기서 종료가 11월30일 이상인것 찾기
}

int main() {
	Init();
	Solve();
	return 0;
}