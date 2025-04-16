#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

long long INF = 9876543210;
long long N, M;
std::vector <std::pair <long long, long long>> Get;

bool CMP(std::pair <long long, long long> A, std::pair <long long, long long> B) {
	if (A.first > B.first) return false;
	else if (A.first < B.first) return true;
	else {
		if (A.second <= B.second) return false;
		else return true;
	}
}

void Input() {  //입력
	long long Weight, Price;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> Weight >> Price;
		Get.push_back({ Price, Weight });
	}
	std::sort(Get.begin(), Get.end(), CMP);
}

void Solve() {
	long long Ans = INF;
	long long Sum = 0;
	for (int i = 0; i < Get.size(); i++) {
		Sum += Get[i].second;
		if (Sum >= M) { // 넘으면
			long long Price = 0;
			for (int j = i; j >= 0; j--) {
				if (Get[i].first != Get[j].first) break;
				else {
					Price += Get[j].first;
				}
			}
			Ans = std::min(Ans, Price);
			for (int j = i + 1; j < Get.size(); j++) {
				if (Get[j].first > Get[i].first) Ans = std::min(Ans, Get[j].first);
			}
			break;
		}
	}
	if (Ans == INF) std::cout << -1;
	else std::cout << Ans;
}

int main() {
	Input();
	Solve();
}