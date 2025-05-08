// 2831
#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
priority_queue<p, vector<p>, greater<p>>q, q2;
int main() {

    int n,m;
    cin >> n >> m;

    //vector<pair<int,int>>v;
    for (int i = 0;i < n;i++) {
        for (int p = 0;p < m;p++) {
            int num;
            cin >> num;
            if (num) {
                /*cout << i << "push" << p << endl;*/
                q.push({ i, p });
            }
        }
    }

    int ans = 0,x,y;
    int cury = 0, curx = 0;
    while (!q.empty()) {
        while (!q.empty()) {
            x = q.top().first, y = q.top().second; q.pop();
            if (x >= curx && y >= cury) {
                curx = x, cury = y;  //0에서 시작
            }
            else {
                q2.push({ x,y });  // chain 넣기
            }
        }
        ans++;
        curx = cury = 0;
        while (!q2.empty()) {
            q.push(q2.top()), q2.pop();
        }
    }
    cout << ans;
}