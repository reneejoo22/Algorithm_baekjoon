#include <iostream>
#include <vector>
#include<algorithm>
#include <queue>
using namespace std;

#define max 105

vector<int> v[max];   // 0으로 초기화
bool visited[max] = { false, };  // false로 초기화...
int ans[max] = { 0, };
int p, c;  // 촌수 계산해야할 두 수.

void BFS(int start) {
    queue<int>q;  // 다음에 방문할 곳 리스트
    visited[start] = true;

    q.push(start);
    ans[start] = 0;  //촌수 0부터 시작

    while (!q.empty()) {
        int now = q.front(); //3
        q.pop();  // 방문했으니 pop

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];  // 1

            if (!visited[next]) {   //방문 안했으면 
                visited[next] = true; //방문 한 것으로 바꾸고
                ans[next] = ans[now] + 1; // 촌수 증가_그 전 방문 한 곳 촌수
                q.push(next);
            }
        }
    }

}
int main() {
    int n;
    cin >> n;
    cin >> p >> c;
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);  // 양방향 연결
    }

    BFS(p);
    if (ans[c] == 0) {
        cout << -1;
    }
    else {
        cout << ans[c];
    }
}