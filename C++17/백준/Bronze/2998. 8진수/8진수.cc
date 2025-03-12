#include <iostream>

#include <cmath>

#include <string>

using namespace std;

 

int main() {

    string n, ans;
    cin >> n;

    int len = n.size();
    int sum = 0;
    int cnt = 0;

    for (int i = len-1; i >= 0; i--)

    {

        cnt++;
        //1을 발견했다면 2^(cnt-1)해준다.

        if(n[i]=='1')
            sum += pow(2, cnt-1);

        //마지막이라면 더해주고 루프 탈출

        if (i == 0)
        {
            ans += sum + '0';
            break;
        }
        //3번째글자가 되었다면 초기화
        if (cnt == 3)
        {
            ans += sum + '0';
            sum = 0;
            cnt = 0;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--)

        cout << ans[i];

}