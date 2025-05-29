#include<bits/stdc++.h>

 

using namespace std;

 

int triangleNum[1001];

 

bool FindTri(int n) {

    for(int i = 1; i <= 45; i++) {

        for(int j = 1; j <= 45; j++) {

            for(int k = 1; k <= 45; k++) {

                if(triangleNum[i] + triangleNum[j] + triangleNum[k] == n) {

                    return true;

                }

            }

        }

    }

    return false;

}

 

int main() {

    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

 

    int t;

    cin >> t;

    

    for(int i = 1; i <= 45; i++) {

        triangleNum[i] = i * (i + 1) / 2;

    }

 

    for(int i = 0; i < t; i++) {

        int num;

        cin >> num;

 

        cout << FindTri(num) << "\n";

    }

}