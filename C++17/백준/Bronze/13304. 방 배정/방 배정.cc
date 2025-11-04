#include <iostream>
using namespace std;
int n, k, q, w, a[5];
int main() {
	cin >> n >> k;
	while (n--) {
		cin >> q >> w;
		if (w < 3) a[0]++;
		else if (w < 5)
			if (q)	a[1]++;
			else a[2]++;
		else
			if (q) a[3]++;
			else a[4]++;
	}
	for (q = 0, w = 0; q < 5; q++)
		w += a[q] / k + (a[q] % k ? 1 : 0);
	cout << w << endl;
}