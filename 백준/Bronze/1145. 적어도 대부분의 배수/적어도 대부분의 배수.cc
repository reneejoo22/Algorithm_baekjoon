#include <iostream>
using namespace std; 
int main() { 	
    int arr[5] = {};	
    int min = -1;	
    for (int i = 0; i < 5; i++) {		
        cin >> arr[i];		
        if (min == -1 || min > arr[i]) min = arr[i];	
    }	 	
    int cnt = 0;	
    int t = min-1;	
    while (cnt < 3) {		
        t++;		
        cnt = 0;		
        for (int i = 0; i < 5; i++) {			
            if (t % arr[i] == 0) cnt++;		 
        }	
    }	
    cout << t << endl;
}
