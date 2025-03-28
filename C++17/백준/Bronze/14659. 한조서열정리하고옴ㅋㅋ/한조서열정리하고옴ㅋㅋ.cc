//11508
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[30001] = { 0, };

int main() {
	
	int n;
	cin >> n;
	
	vector<int>v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}

    int result = -1;
    for (int i = 0;i < n - 1;i++) {
        for (int j = i + 1;j < n;j++) {
            if (v[i] > v[j]) ans[i]++;
            else break;
        }
        result = max(ans[i], result);
    }
    cout << result;

}
