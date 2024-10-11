//10월 11일~^^ 1094번 문제
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int>A(8);
    int x = 64;

    for (int j = 1; j < 8; j++) {
        A[j] = x;
        x = x / 2;
    }
    
    int i = 1;
    int count = 0;

    while (n != 0) {
        if (A[i] > n) { //23
            i++;
        }
        else if (A[i] <= n) { //23
            n = n - A[i];
            count++;

            if (n != 0) {
                i++;
            }
            else {
                break;
            }
        }
    }

    cout << count;

}

/*
0
64
32
16
8
4
2
1

*/