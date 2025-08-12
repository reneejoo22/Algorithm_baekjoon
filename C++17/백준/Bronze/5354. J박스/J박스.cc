#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int box;
        cin >> box;
        for (int i = 0; i < box; i++)
        {
            for (int j = 0; j < box; j++)
            {
                if (i != 0 && i != box - 1 && j != 0 && j != box - 1)
                    cout << "J";
                else
                    cout << "#";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
