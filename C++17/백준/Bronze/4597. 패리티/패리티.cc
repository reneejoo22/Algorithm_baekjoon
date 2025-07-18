#include <iostream>
using namespace std;

int main()
{
    string s;

    while (1)
    {
        cin >> s;

        if (s == "#")
            break;

        int cnt = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                cnt++;
        }

        if (s[s.length() - 1] == 'e')
        {
            if (cnt % 2 == 0)
                s[s.length() - 1] = '0';
            else
                s[s.length() - 1] = '1';
        }
        else
        {
            if (cnt % 2 == 0)
                s[s.length() - 1] = '1';
            else
                s[s.length() - 1] = '0';
        }

        cout << s << '\n';
    }

    return 0;
}