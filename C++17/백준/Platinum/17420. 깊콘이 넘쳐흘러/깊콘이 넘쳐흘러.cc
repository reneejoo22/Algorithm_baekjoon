// 17420
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int A[100001];
int B[100001];

typedef struct gf {
    int a; // 만료일
    int b; // 계획일
} gf;

vector<gf>v;

bool cmp(gf A, gf B) {
    if (A.b == B.b) {
        return A.a < B.a;  // 계획일이 같으면 만료일에 맞춰서 오름차순
    }
    else {
        return A.b < B.b;  // 계획일에 맞춰 오름차순...
    }
}

int main() {

    int n;
    cin >> n;

    int i;
    for (i = 0;i < n;i++) {
        cin >> A[i];
    }
    for (i = 0;i < n;i++) {
        cin >> B[i];
    }
    for (i = 0;i < n;i++) {
        v.push_back({ A[i], B[i] });
    }

    sort(v.begin(), v.end(), cmp);

    int pre_max = v[0].b;  //이전 구간 최댓값...
    int cur_max = -1;   // 현재 구간 최댓값

    long long ans = 0;
    for (i = 0;i < n;i++) {
        if (pre_max > v[i].a) {  // 연장해야함
            
            if (pre_max < v[i].b) { //계획일이 더 크면 계획일로 바꿈
                pre_max = v[i].b;
            }

            int cnt = ((pre_max - v[i].a) + 29) / 30;
            v[i].a += (cnt * 30);
            ans += cnt;
        }
        // 연장 후 pre_max 변경

        cur_max = max(cur_max, v[i].a);
        if ((i + 1) < n && v[i].b != v[i + 1].b) {  // n을 벗어나지 않게, 그리고 구간이 다르다면
            pre_max = cur_max;  // 이전값을 갱신
        }
    }

    cout << ans << endl;
}

/*
24 2   3 29 2
25 30 30 30 35
*/