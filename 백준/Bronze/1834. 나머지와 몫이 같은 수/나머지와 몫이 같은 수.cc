#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int main() {
    long long n;
    long long res = 0;
    cin >> n;
    
    for (long long i = 1; i < n; i++){
        res += (n + 1) * i;
    }
    cout << res;
}