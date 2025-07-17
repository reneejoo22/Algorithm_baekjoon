#include <iostream>
using namespace std;
int N, num, prevNum;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> N;

        if (N == 0)
        {
            break;
        }

        prevNum = -1;

        while (N--)
        {
            cin >> num;

            if (prevNum == num)
            {
                continue;
            }

            prevNum = num;

            cout << num << " ";
        }

        cout << "$\n";
    }
    return 0;
}