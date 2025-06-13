#include <iostream>

#include <vector>

using namespace std;

vector<int> v1; // 1차 순서

vector<int> v2; // 최종 순서

int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    // 1차 순서를 입력받아 v1에 저장

    for (int i = 1; i <= n; i++) {

        int x;

        cin >> x;

        v1.insert(v1.begin() + (x - 1), i);

    }

    // v1에서 m명까지 남기기

    while (v1.size() > m) {

        v1.pop_back();

    }

    // 2차 순서에 따라 v2에 최종 순서 정리

    for (int i = 1; i <= m; i++) {

        int x;

        cin >> x;

        v2.insert(v2.begin() + (x - 1), v1.back());

        v1.pop_back();

    }

    // v2에서 상위 3명만 남기기

    while (v2.size() > 3) {

        v2.pop_back();

    }

    // 결과 출력

    for (auto it = v2.begin(); it != v2.end(); it++) {

        cout << *it << '\n';

    }

    return 0;

}