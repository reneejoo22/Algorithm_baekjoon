#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;

    int ct[51]; fill(ct, ct+51,0);
    //어떤 연속성을 띈 자료구조(벡터나 배열 같은)의 시작점부터 연속된 범위를 어떤 값이나 객체로 모두 지정하고 싶을 때 사용하는 함수이다.
    for(int i = 0,N;i<n;i++){
        cin>>N, ct[N]++;
    }

    for(int q = 50;q>=0;q--){
        if(ct[q] == q){
            cout<<q;
            return 0;
        }
    }

    cout<<-1;

    
}