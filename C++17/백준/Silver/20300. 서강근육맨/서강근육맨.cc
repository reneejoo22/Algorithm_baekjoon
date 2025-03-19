//20300
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;

	vector<long long>m(n);
	for (int i = 0;i < n;i++) {
		cin >> m[i];
	}

	sort(m.begin(), m.end());

	long long max = 0;
	vector<long long>tmp;
	if (n % 2 == 1) {
		max = m[n - 1];
		tmp.push_back(max);  //끝 값 지우기
		n--;
	}


	for (int i = 0; i < n / 2; i++) {
		long long cand = m[i] + m[n - i - 1];
		tmp.push_back(cand);
		if (max < cand) {
			max = cand;
		}
	}

	cout << max;
}

