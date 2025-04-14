#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  int k = 0, y = 0;
  for (char c : s) {
    if (c == 'K' && k == 0)
      k++;
    if (c == 'O') {
      if (k == 1)
        k++;
      if (y == 1)
        y++;
    }
    if (c == 'R' && k == 2)
      k++;
    if (c == 'E') {
      if (k == 3)
        k++;
      if (y == 4)
        y++;
    }
    if (c == 'A' && k == 4)
      k++;
    if (c == 'Y' && y == 0)
      y++;
    if (c == 'N' && y == 2)
      y++;
    if (c == 'S' && y == 3)
      y++;
    if (c == 'I' && y == 5)
      y++;
    if (k == 5) {
      cout << "KOREA";
      return 0;
    } else if (y == 6) {
      cout << "YONSEI";
      return 0;
    }
  }
  return 0;
}