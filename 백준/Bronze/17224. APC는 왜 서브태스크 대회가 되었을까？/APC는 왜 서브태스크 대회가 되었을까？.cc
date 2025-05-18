#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, K; // 문제 개수, 역량, 풀 수 있는 문제의 최대 개수
int a, b; // 쉬운 버전, 어려운 버전
vector<pair<int, int>> v;

int main()
{
    // 문제 입력, 벡터에 난이도별로 저장
    cin >> N >> L >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    // 오름차순 정렬
    sort(v.begin(), v.end());

    int sum = 0; // 출력값 변수 

    // 어려운 난이도가 L보다 작거나 같으면(풀 수 있으면) 140점 적립, K(풀 수 있는 문제 개수) -1
    for (int i = 0; i < N; i++)
    {
        if (K == 0) break; // K가 0이면 종료
        if (L >= v[i].second)
        {
            sum += 140;
            K--;
        }
    }
    // 쉬운 난이도가 L보다 작거나 같고(풀 수 있으면) AND 어려운 난이도가 L보다 크면(풀 수 없으면),100점 적립, K(풀 수 있는 문제 개수) -1
    for (int i = 0; i < N; i++)
    {
        if (K == 0) break; // K가 0이면 종료
        if (L >= v[i].first && L < v[i].second)
        {
            sum += 100;
            K--;
        }
    }

    // 출력
    cout << sum;

    return 0;
}