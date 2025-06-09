// 2590
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int>v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }

    int maxLen = 2, tmp = 2;
    for (int i = 0;i < n - 2;i++) {
        if (v[i] <= v[i + 1] && v[i + 1] <= v[i + 2]) {
            tmp = 2;
        }
        else if (v[i] >= v[i + 1] && v[i + 1] >= v[i + 2]) {
            tmp = 2;
        }
        else {
            tmp++;
        }
        maxLen = max(tmp, maxLen);
    }

    cout << maxLen;
    return 0;
}