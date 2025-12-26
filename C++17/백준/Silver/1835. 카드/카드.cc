#include <iostream>
#include <deque>

using namespace std;

int main() {
	int n;
	cin >> n;

	deque<int>d;
	d.push_back(n);
	for (int i = n - 1; i > 0; i--) {
		d.push_front(i);
		for (int j = 0; j < i; j++) {
			d.push_front(d.back());
			d.pop_back();
		}
	}

	while (!d.empty()) {
		cout << d.front() << ' ';
		d.pop_front();
	}
}

/*
1이면 한번 뒤로
2이면 두번 뒤로 
3이면 3번 뒤로
4 이면 4번 뒤로

2 1 4 3
*/