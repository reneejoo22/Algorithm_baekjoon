#include <iostream>
#include <string>
using namespace std;
int main()
{
    char c;
    string k;
    while (1)
    {
        int cnt = 0;
        cin >> c;
        if (c == '#') { return 0; }
        getline(cin, k);
        for (int i = 0; i < k.size(); i++)
        {
            if ('A' <= c && c <= 'Z')
            {
                if (k[i] == c || k[i] == c + 32)
                    cnt++;
            }
            else if ('a'<= c && c <= 'z')
            {
                if (k[i] == c || k[i] == c - 32)
                    cnt++;
            }
        }
        cout << c << ' ' << cnt << '\n';
    }
}