#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 987654321;

int N, T, a, b, c, result = -1;

int main()
{
    ios_base::sync_with_stdio(0); 
	cin.tie(0);

    cin >> N >> T;
    int minV = 1000000;

    for(int i=1; i<=N; i++) 
    {
        cin >> a >> b >> c;
        int tmp = a; //시작점
        for(int j=1; j<=c; j++)
        {
            if(tmp >= T) 
            {
                result = tmp-T;
                break;
            }
            tmp += b; //다음 버스
        }
        if(result==-1) continue; //-1은 불가능한 경우이므로 스킵
        minV = min(result, minV); //최솟값 저장
    }
    cout<< ((result==-1) ? -1 : minV);



    return 0;
}