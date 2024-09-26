#include<iostream>
using namespace std;

int main() {
	char pan[8][9];	
	
	for (int i = 0; i < 8; i++){
		cin >> pan[i];
    }
    
    int ans = 0;
	for (int i = 0; i < 8; i++) {
		for (int p = i % 2; p < 8; p += 2) {
			if (pan[i][p] == 'F')
				ans++;
		}
	}

	cout << ans << endl;
}