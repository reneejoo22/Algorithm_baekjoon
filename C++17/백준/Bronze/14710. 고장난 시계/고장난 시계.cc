#include<bits/stdc++.h>
using namespace std;
int a, b;
int main(){
    cin >> a >> b;
    if(a % 30 * 12 == b) cout << "O" << "\n";
    else cout << "X" << "\n";
    return 0;
}