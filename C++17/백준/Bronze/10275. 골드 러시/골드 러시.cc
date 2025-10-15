#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll CNT(ll x)
{
    ll cnt = 0;
    while (x)
    {
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}

int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T, a, b, c;
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;
        cout << CNT((ll)(pow(2, a)) ^ b ^ c) << "\n";
    }
}