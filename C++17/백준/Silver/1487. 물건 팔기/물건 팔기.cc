#include<bits/stdc++.h>
 
using namespace std;
 
vector<pair<int, int>> input;
int n;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int product, delivery;
        cin >> product >> delivery;
        
        input.push_back({product, delivery});
    }
    
    sort(input.begin(), input.end());
    
    int maxCost = 0;
    int maxProfit = 0;
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            int curProfit = input[i].first - input[j].second;
            if(curProfit > 0) sum += curProfit;
        }
        if(maxProfit < sum) {
            maxProfit = sum;
            maxCost = input[i].first;
        }
    }
    
    cout << maxCost;
}