#include <iostream>
#include <cmath>
using namespace std;
#define MAX_NUM 236196

int visit[MAX_NUM];
int P;
int answer = 0;

void DFS(int A){
    int origin = A;
    int next = 0;

    visit[A-1]++;

    while(A > 0){
        next += (int)pow( A % 10 , P);
        A /= 10;
    }

    if(visit[next-1] == 2) return ;
     
    DFS(next);

    if(visit[origin-1] == 1) answer++;

}

int main(int argc, char** argv){
    int A , num;

    cin >> A >> P;

    DFS(A);

    cout << answer;
}