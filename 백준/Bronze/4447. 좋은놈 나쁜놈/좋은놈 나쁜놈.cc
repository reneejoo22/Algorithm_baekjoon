#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    int test;
    cin>>test;
    cin.ignore();
 
    string str;
 
    for(int i=0; i<test; i++){
        getline(cin, str);
 
        int cntg=0; // g,G의 개수 카운트
        int cntb=0; // b,B의 개수 카운트
 
        for(int i=0; i<str.length(); i++){
            if(str[i]=='G'||str[i]=='g'){
                cntg++;
            }
            else if(str[i]=='B'||str[i]=='b'){
                cntb++;
            }
        }
 
        if(cntg==cntb){
            cout<<str<<" is "<<"NEUTRAL\n";
        }
        else if(cntg>cntb){
            cout<<str<<" is "<<"GOOD\n";
        }
        else{
            cout<<str<<" is "<<"A BADDY\n";
    }
 
    }
}
