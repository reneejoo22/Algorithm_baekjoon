#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>
using namespace std;

#define max 105

vector<int> v[max];   // 0으로 초기화
bool visited[max];  // false로 초기화...
int ans = 0;

void DFS(int k) {
    visited[k] = true;

    for (int i = 0; i < v[k].size();i++) {
        int next = v[k][i];  //다음 갈 자리
        
        if (!visited[next]) {   
            /*cout << next << endl;*/  
            // 아 그러니까 반복문 돌아도 함수 호출이 먼저.
            ans++;
            DFS(next);
        }
    }
    return;

}
int main() {
    int n, m;
    cin >> n;
    cin >> m;

    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);  // 양방향 연결
    }

    DFS(1);
    cout << ans;
}
