#include<iostream>
#include<string>
#include<vector>
using namespace std;

string goal;
int n;
int goalChar[26];
vector<pair<int, string>>v(16);  // price, book
int res = 987654321;
int alphabet[26];

bool check() {
    for (int i = 0; i < 26;i++) {
        if (goalChar[i] > alphabet[i]) {
            return false;
        }
    }
    return true;
}

void combination(int cnt, int priceSum) {

    if (cnt == n) {
        if (check()) {  // false면 맞는게 하나도 없는 것... true, false든 return
            res = min(res, priceSum);
           /* cout << cnt<<". "<< "res " << res << endl;*/
            // 돌아가는 과정에서 예전 누적 값으로
        }
        /*cout << "check false" << endl;*/
        return;
    }
    for (int i = 0;i < v[cnt].second.length();i++) {  // 한 책 다 돌기
        alphabet[v[cnt].second[i] - 'A']++;  //
    }
    /*cout << cnt << ". " << v[cnt].second << " priceSum: " << priceSum << endl;*/
    combination(cnt + 1, priceSum + v[cnt].first);
    for (int i = 0; i < v[cnt].second.length(); i++) {  // cnt 다시 0부터 시작
        alphabet[v[cnt].second[i] - 'A']--;
    }
    combination(cnt + 1, priceSum);
}

int main() {
    cin >> goal >> n;
    for (int i = 0; i < goal.length();i++) {
        goalChar[goal[i] - 'A']++;
    }
 
    for (int i = 0;i < n;i++) {
        cin >> v[i].first >> v[i].second;
    }

    combination(0, 0);
    if (res == 987654321) {
        cout << -1;
    }
    else {
        cout << res;
    }
}