#include <iostream>
using namespace std;

int main() {
    double o, w; // 적정 체중 o, 실제 체중 w
    int scenario = 1; // 시나리오 번호
    
    while (true) {
        bool isRIP = false; // 펫의 생존 여부

        cin >> o >> w;

        // 시나리오 종료
        if (o == 0 && w == 0) break;

        while (true) {
            char EF; // 펫에게 가할 각 작용
            int n;

            cin >> EF >> n;

            // 시나리오 하나 종료
            if (EF == '#' && n == 0) break;

            // 펫이 살아있는 경우 입력한 작용을 실행한다.
            if (!isRIP) {
                if (EF == 'E') w -= n; // 운동
                else if (EF == 'F') w += n; // 먹이

                if (w <= 0) isRIP = true; // 사망
            }
        }
        
        // 출력
        if (isRIP)
            printf("%d RIP\n", scenario); // 펫 사망
        else if (w > o / 2 && w < o * 2)
            printf("%d :-)\n", scenario); // 행복
        else
            printf("%d :-(\n", scenario); // 슬픔

        scenario++;
    }

    return 0;
}