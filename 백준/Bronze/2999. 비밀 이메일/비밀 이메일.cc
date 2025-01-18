#include <iostream>
#include <math.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	
	int num = str.length();
	int i, j, k, row = 0, col = 0;

	for (i = sqrt(num); i > 0; i--) { 
		if (num % i == 0) {
			col = i; 
			row = num / col; 
			break;
		}
	}

	char** arr = new char* [row]; 
	for (i = 0; i < row; i++) {
		arr[i] = new char[col];
	}
	i = 0;
	while(i<num){
		for (j = 0; j < row; j++) { 
			for (k = 0; k < col; k++) {
				arr[j][k] = str[i++];
			}
		}
	}

	for (i = 0; i < col; i++) { 
		for (j = 0; j < row; j++) {
			cout << arr[j][i];
		}
	}
}