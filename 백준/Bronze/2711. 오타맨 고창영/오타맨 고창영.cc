#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    int test;
    cin>>test;
 
    for(int i=0; i<test; i++){
        int position;
        string str;
        cin>>position>>str;
 
        for(int i=0; i<str.length(); i++){
            if(i!=position-1){ // i와 position이 같지 않을때만 출력 
                cout<<str[i];
            }
        }
        cout<<"\n";
    }
    return 0;
}
