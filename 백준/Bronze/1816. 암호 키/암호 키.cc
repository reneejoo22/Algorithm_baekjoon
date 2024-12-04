// 1816. 암호 키
#include <iostream>
#include <vector>
 
using namespace std;
 
bool IsPrime(int a)
{
    if(a == 2) return false;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0) return false;
    }
 
    return true;
}
 
 
 
int main()
{
    int n;
    cin >> n;
 
    vector<int> prime;
 
    for (int i = 2; i <= 1000000; i++)
    {
        if (IsPrime(i))
        {
            prime.push_back(i);
        }
    }
 
 
    long long m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
 
        bool flag = true;
        for (int j = 0; j < prime.size(); j++)
        {
            if (m % prime[j] == 0)
            {
                flag = false;
            }
        }
 
        if (flag == true)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
 
    return 0;
}