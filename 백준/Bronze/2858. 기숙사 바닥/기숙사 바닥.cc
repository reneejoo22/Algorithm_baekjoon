#include <iostream>

using namespace std;

int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int CntRed, CntBrown;

    cin >> CntRed >> CntBrown;



    for (int i = 3; ;i++){
        for(int j = i; j >= 3; j--){
             int TryRed, TryBrown;
             TryBrown = (i-2) * (j-2);
             TryRed = i * j - TryBrown;

             if (TryRed == CntRed && TryBrown == CntBrown){
                 cout << i << ' ' << j;
                 return 0;
             }

        }
    }

    return 0;
}