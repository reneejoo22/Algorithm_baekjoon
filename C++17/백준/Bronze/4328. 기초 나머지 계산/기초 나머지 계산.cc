#include <iostream>

#include <string>

#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(0);	cin.tie(0);

	

	int b; string p, mm;

	while (cin >> b >> p >> mm) {

		int m = 0;

		for (auto l : mm) m = m * b + l - '0';

		if (m == 0) {

			cout << p << '\n';

			continue;

		}

		int ans = 0;

		for (auto l : p) {

			ans = ans * b + l - '0';

			ans %= m;

		}

		if (ans == 0) {

			cout << 0 << '\n';

			continue;

		}

		stack<int> stk;

		while (ans) {

			stk.push(ans % b);

			ans /= b;

		}

		while (!stk.empty()) {

			cout << stk.top();

			stk.pop();

		}

		cout << '\n';

	}

}