#include <iostream>
using namespace std;
long long f[1001], c, n,sum;
int main() {
    
    cin >> n; 
    
    for (int i = 0; i < n; i++)
        cin >> f[i];
    cin >> c;
    for (int i = 0; i < n; i++)
    {
        if (f[i] / c*c >= f[i])
            sum += f[i] / c*c;
        else
            sum += (f[i] / c + 1)*c;
    }
    cout << sum << '\n';
}