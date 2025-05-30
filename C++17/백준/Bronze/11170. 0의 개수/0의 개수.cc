// 2590
#include <iostream>
#include <vector>
#include<string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int a, b;
    for (int i = 0;i < t;i++) {
        cin >> a >> b;

        int cnt = 0;
        int sum = 0;

        for (int i = a;i <= b;i++) {
            string str = to_string(i);
            for (int p = 0;p < str.length();p++) {
                if (str[p] == '0') {
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}