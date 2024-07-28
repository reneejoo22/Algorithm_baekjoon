//baekjoon 1267
#include<iostream>
#include<vector>
using namespace std;

int Young();
int Min();
int N;
vector<int> A;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int time;
		cin >> time;
		A.insert(A.begin()+i, time);
	}


	int youngFee = Young();
	int minFee = Min();

	if (youngFee > minFee) {
		cout << "M " << minFee;
	}
	else if (youngFee < minFee) {
		cout << "Y " << youngFee;
	}
	else {
		cout << "Y M " << youngFee;
	}

}

int Young() {	//29초에 10원씩

	int Yfee = 0;

	for (int k = 0; k < N; k++) {

		if (A[k] / 30 > 0) {	//30초 이상일때, 20원 이상일때
			Yfee = Yfee+ (A[k] / 30);
			
			if (A[k] % 30 >= 1) {
				Yfee = Yfee + 1;
			}
			else if (A[k] % 30 == 0) {
				Yfee = Yfee + 1;
			}
		}

		else if (A[k] == 0) {
			continue;
		}

		else {	//30초 미만일 때 10원일때
			Yfee = Yfee + 1;
		}
		//cout << A[k];
		//cout << "from Young" << k << " round " << Yfee << "\n";
	}
	return Yfee * 10;
}


int Min() {	//59초에 15원씩

	int Mfee = 0;

	for (int k = 0; k < N; k++) {

		if (A[k] / 60 > 0) {	//60초 이상일때, 30원 이상일때
			Mfee = Mfee + (A[k] / 60);

			if (A[k] % 60 >= 1) {
				Mfee = Mfee + 1;
			}
			else if (A[k] % 30 == 0) {
				Mfee = Mfee + 1;
			}
		}

		else if (A[k] == 0) {
			continue;
		}

		else {	//60초 미만일 때 10원일때
			Mfee = Mfee + 1;
		}
		//cout << "from Min" << k << " round " << Mfee << "\n";
	}
	return Mfee * 15;
}
