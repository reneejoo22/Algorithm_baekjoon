#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int n;
    cin >> n;
    if (!n)
      break;
    vector<int> v;
    v.push_back(n);
    n *= n;
    while (1) {
      string s = to_string(n);
      while (s.size() < 8)
        s = "0" + s;
      n = stoi(s.substr(2, 4));
      if (find(v.begin(), v.end(), n) != v.end())
        break;
      v.push_back(n);
      n *= n;
    }
    cout << v.size() << '\n';
  }
  return 0;
}