//1931
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>>A(N);	

	for (int i = 0; i < N; i++) { //종료시간대가 빠른 순으로 정렬
		cin >> A[i].second;	//시작시간
		cin >> A[i].first;	//종료시간
	}

	sort(A.begin(), A.end());	//오름차순

	int count = 1;
	int end = A[0].first;	//4

	//cout << "\n\n";
	for (int j = 1; j < N; j++) {
		if (A[j].second >= end) {		//A[j].second 시작시간 > A[pre].first 종료시간
			//cout << A[j].first << " " << A[j].second << "\n";
			count++;
			end = A[j].first;
		}
	}

	cout << count;
}

/*
0,6
1,4
2,13
3,5
3,8
5,7
5,9
6,10
8,11
8,12
12,14

===========

1번방_(1,4), (5,7), (8,11), (12,14)
2번방_(0,6), (6,10)
3번방_(3,5), (5,9)
4번방_(3,8), (8,12)
5번방_ (2,13)

========

정렬

4,1==
5,3
6,0
7,5==
8,3
9,5
10,6
11,8==
12,8
13,2
14,12==

(1,4), (5,7), (8,11), (12,14)


end = 4, count = 1;

<1round>

count = 2;
end = 7

<2round>

count = 3;
end = 11

<3round>

count = 4;
end = 14

-----finish------

*/