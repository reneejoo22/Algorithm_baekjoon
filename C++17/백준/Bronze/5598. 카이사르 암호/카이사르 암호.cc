#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string str;
    cin>>str;
 
    int len = str.length();
 
    char ch;
 
    for(int i=0; i<len; i++){
        char c = str[i];
        // A = 65 B = 66 C = 67
        // c가 A,B,C일때만
        // A->X B->Y C->Z
        if(int(c)>=65&&int(c)<=67){
            ch = int(c)+23;
        }
        else{
// ex) M = 77 J = 74
            ch = int(c)-3;
        }
        cout<<ch;
    }
    return 0;
}