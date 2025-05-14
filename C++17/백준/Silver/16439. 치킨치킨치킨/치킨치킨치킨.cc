// 16439
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int arr[30][30];
int pick[3];
int ans;

void comb(int idx, int cnt) {
	if (cnt != -1) {
		pick[cnt] = idx;  //pick = [0, 1, 2]//  pick = [0, 2, 2] // pick = [0, 2, 3]
	}
	if (cnt == 2) {  // pick 다 채워지면
		int sum = 0;
		for (int i = 0;i < n;i++) { //회원수
			int score = 0;
			for (int j = 0;j < 3;j++) {
				score = max(arr[i][pick[j]], score);
			}
			sum += score;
		}
		ans = max(sum, ans);

		/*for (int q = 0;q < 3;q++) {
			cout << pick[q] << " ";
		}
		cout << endl;*/

		return;
	}

	for (int i = idx;i < m;i++) {  // -1, 5_ 6번
		comb(i + 1, cnt + 1);    // 0, 0... for 문 생성_1,1.... for문 생성_2,2_pick 완성
								// 0,1,2했을 때는  return 했을 때라서 ... 생성한 마지막 for문이 다 돌때까지 갱신 X
	}

	// comb(-1,-1)...
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0;i < n;i++) {
		for (int q = 0;q < m;q++) {
			cin >> arr[i][q];
		}
	}
	comb(-1, -1);
	cout << ans;
}