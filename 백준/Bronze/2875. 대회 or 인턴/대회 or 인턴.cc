//2875
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M, K;    //여학생, 남학생, 인턴십
    cin >> N >> M >> K;

    int count = min(M, N / 2);//둘 중 작은 값 반환

    count = min(count, (N + M - K) / 3);

    cout << count;
}
