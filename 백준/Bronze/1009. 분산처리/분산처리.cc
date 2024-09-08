//1009
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;		// 테스트 케이스 개수 입력 받기

    for (int i = 0; i < t; i++) 
    {
        int a, b, result = 1;
        cin >> a >> b;

        for (int j = 0; j < b; j++) 
        {
            result = (result * a) % 10;		
        }

        if (result == 0) 
        {
            cout << 10 << endl;	
        }
        else 
        {
            cout << result << endl;
        }
    }
    return 0;
}