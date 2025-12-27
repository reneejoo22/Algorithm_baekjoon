#include <iostream>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int T; cin >> T;
    while (T--) {
        bool check[10001] = { false };
        int sum = 0;
        int N; cin >> N;
        for (int i = 1; i<=N/2; i++) {    
            if (N % i == 0) check[i] = true;
            }
 
        for (int i = 1; i <= N/2; i++) {
            if (check[i])sum += i;
        }
 
        if (sum > N) cout << "Abundant" << "\n";
        else if (sum < N) cout << "Deficient" << '\n';
        else cout << "Perfect" << "\n";
 
 
    }
}