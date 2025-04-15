#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int>v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());  // 오름

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(v[i] - (i + 1));
    }

    cout << sum;
    return 0;
}