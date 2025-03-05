//1461
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sumWalk(vector<int>a, int m) {
	int sum = 0;
	for (int i = a.size() - 1; i >= 0;i -= m) {
		sum += a[i] * 2;
	}
	return sum;
}

int main() {
	int m, n;
	cin >> m >> n;

	vector<int>map, Mmap;
	for (int i = 0;i < m;i++) {
		int num;
		cin >> num;
		if (num < 0) {
			num *= -1;
			Mmap.push_back(num);
		}
		else {
			map.push_back(num);
		}
	}

	sort(map.begin(), map.end());
	sort(Mmap.begin(), Mmap.end());

	int sum = 0;
	sum += sumWalk(map, n) + sumWalk(Mmap, n);
	//맞아떨어지지 않으면 더하고, 끝 수가 더 작은 건 *2 하기

	if (map.size() > 0 && Mmap.size() > 0) {
		if (map[map.size() - 1] < Mmap[Mmap.size() - 1]) {
			sum -= Mmap[Mmap.size() - 1];
		}
		else {
			sum -= map[map.size() - 1];
		}
	}
	else if (Mmap.size() > 0) {
		sum -= Mmap[Mmap.size() - 1];
	}
	else {
		sum -= map[map.size() - 1];
	}
	cout << sum;
	
}

