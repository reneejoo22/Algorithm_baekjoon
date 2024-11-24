#include <iostream>
using namespace std;

int gcd(int a, int b) //유클리드호제
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
    int x, y;
    int ans;
    cin>>x>>y;
    
    if ( gcd(x, y) == 1 ){
        ans = x + y - 1;
    }
    else{
        ans = x + y - gcd(x, y);
    }
    
    cout<<ans;

    return 0;
}