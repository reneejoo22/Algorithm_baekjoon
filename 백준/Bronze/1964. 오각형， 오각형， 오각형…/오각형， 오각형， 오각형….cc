#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int sum = 5;
    int num = 7;
    
    for(int i = 2;i<=n;i++){
        sum += num; //12
        num += 3;   //10

        sum %= 45678;
        num %= 45678;
    }

    cout<<sum;
    return 0;
}