//1105
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int l,r;
	cin >> l >> r;

	int gap = r - l;

	
	string L = to_string(l);
	string R = to_string(r);
	int where = 10;
	int cnt = 0;

	if (L.size() != R.size()) {
		cout << "0";
		return 0;
	}
	else {
		for (int i = 0;i < L.size();i++) {
			if (L[i] != R[i]) {
				break;
			}
			if (L[i] == '8' && L[i] == R[i]) {
				cnt ++;
			}
		}
	}

	cout << cnt;
	return 0;
}
/*
L.size() 의 반환형은 int가 아니라 size_t임 즉 0 이상만 가능
그래서 int에 값을 저장하면 경고가 생길수있음
static_cast<데이터타입>
위에 문장을 써서 강제 형변환 가능!
*/