#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s = "100", tmp;

    cin >> tmp;

    for (int i = 0; i < tmp.length(); i++)
    {
        if (tmp[i] == 'A')
            swap(s[0], s[1]);
        else if (tmp[i] == 'B')
            swap(s[1], s[2]);
        else
            swap(s[0], s[2]);
    }

    for (int i = 0; i < 3; i++)
    {
        if (s[i] == '1')
            cout << i + 1 << '\n';
    }

    return 0;
}