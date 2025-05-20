// 16439
#include <iostream>
#include <utility> 
#include <tuple>
using namespace std;
int ans;
string s;

void isPalindrome(int l, int r, bool dn) {
    
    int cnt;
	while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        }

        else {
            if (dn) { //첫 시작이 아니라면...
                if (ans == 3) {
                    ans = 2;
                }
                return;
            }
            isPalindrome(l + 1, r, true);
            isPalindrome(l, r - 1, true);
            return;
        }
	}

    ans = dn;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
        cin >> s;

        ans = 3;
        isPalindrome(0, s.size() - 1, false);    
        cout << ans << endl;
    }
}