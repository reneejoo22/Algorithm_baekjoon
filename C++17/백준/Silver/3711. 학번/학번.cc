#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include <iostream>
#define endl '\n'
using namespace std;

//백준 3711번 코드
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        int* arr = new int[num];
        for (int j = 0; j < num; j++) {
            cin >> arr[j];
        }

        int result = 0;     // 답 저장할 변수
        while (true) {
            result++;
            int retry = 0;     // 0일때는 출력, 1일때는 다시 나눗셈 수행
            int extra[100001] = { 0 };   // 나머지 저장 (10만까지 해야함)
                // 보통은 연결리스트로 하는 것 같음
            for (int j = 0; j < num; j++) {
                extra[arr[j] % result]++;
                if (extra[arr[j] % result] > 1) {   // 같은 나머지 2개 이상일 때
                    retry++;
                    break; 
                }
            }
            if (retry > 0) { continue; }
            cout << result << endl;   break;
        }
    }
}