//2712
#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		pair<double, string>temp;
		cin >> temp.first >> temp.second;

		if (temp.second == "kg")
			printf("%.4lf lb\n", temp.first * 2.2046);

		else if (temp.second == "lb")
			printf("%.4lf kg\n", temp.first * 0.4536);

		else if (temp.second == "l")
			printf("%.4lf g\n", temp.first * 0.2642);

		else if (temp.second == "g")
			printf("%.4lf l\n", temp.first * 3.7854);
	
	}
}