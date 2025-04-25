// 5014
#include <iostream>
#include <vector>
#include<queue>
using namespace std;
#define MAX 1000001

int f, s, g, u, d;  //총 층 수, 현재 있는 곳, 갈 곳, 
vector<int>direction;  // 올라가는 정도, 내려가는 정도

bool visited[MAX] = { false, };       // 방문 했는지 안했는지 확인
int ans[MAX] = { 0, }; //버튼 누른 횟수


void BFS() {
    queue<int>q;  // 앞으로 갈 곳을 넣기
    q.push(s);  // 현재층, 버튼 누른 횟수_ 1, 0
    visited[s] = true;
    /*ans[s] = 0;*/

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0;i < 2;i++) {
            int next = now + direction[i];

            if (next <= f && next >= 1) { // 범위를 초과하지 않게
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                    ans[next] = ans[now] + 1;
                }
            }
            
        }
        /*cout << "where I'm_" << now << " button_" << ans[now] << endl;*/
        
    }

    if (!visited[g]) {
        cout << "use the stairs" << endl;
    }
    else {
        cout << ans[g] << endl;
    }
}
// now 랑 future 써야함_ ans 라는 배열을 만들어서 따로 저장해도


int main() {
    cin >> f>> s>> g>> u>> d;

    direction.push_back(u);
    direction.push_back(d * -1);  // 메모리를 이미 지정한 후에 push_back하면 메모리 늘어남 

    BFS();
}



// // 26099
// #include <iostream>
// #include <vector>
// #include<queue>
// using namespace std;
// #define MAX 1000001
// int f, s, g, u, d;  //총 층 수, 현재 있는 곳, 갈 곳, 올라가는 정도, 내려가는 정도
// queue<int>q;  // 앞으로 갈 곳을 넣기
// bool visited[MAX] = { false, };       // 방문 했는지 안했는지 확인
// int ans[MAX] = { 0, }; //버튼 누른 횟수


// void BFS() {
//     q.push(s);  // 현재층, 버튼 누른 횟수_ 1, 0
//     visited[s] = true;
//     /*ans[s] = 0;*/

//     while (!q.empty()) {
//         int now = q.front();
//         q.pop();

//         if (now + u <= f && now + u >= 1 && !visited[now + u]) {  // 위로 올라갔을 때 초과하지 않아야함
//             int next = now + u;
//             q.push(next);
//             visited[next] = true;
//             ans[next] = ans[now] + 1;

//         }
//         if (now - d <= f && now - d >= 1 && !visited[now - d]) { // 아래로 올라갔을 때 초과하지 않아야함
//             int next = now - d;
//             q.push(next);
//             visited[next] = true;
//             ans[next] = ans[now] + 1;
//         }

//         /*cout << "where I'm_" << now << " button_" << ans[now] << endl;*/
//     }

//     if (!visited[g]) {
//         cout << "use the stairs" << endl;
//     }
//     else {
//         cout << ans[g] << endl;
//     }
// }
// // now 랑 future 써야함_ ans 라는 배열을 만들어서 따로 저장해도


// int main() {
//     cin >> f>> s>> g>> u>> d;
    
//     BFS();
// }
