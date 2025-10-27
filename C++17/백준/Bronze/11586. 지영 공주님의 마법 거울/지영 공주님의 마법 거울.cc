#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
 
    int test;
    cin>>test;
 
    string str;
 
    vector<string> vec;
 
    for(int i=0; i<test; i++){
        cin>>str;
        vec.push_back(str);
    }
 
    int k;
    cin>>k;
 
    if(k==1){   
        for(int i=0; i<test; i++){
            cout<<vec[i]<<"\n";
        }
    }
 
    else if(k==2){
        for(int i=0; i<test; i++){
            // reverse 헤더파일 = <algorithm>
            reverse(vec[i].begin(), vec[i].end());  // keypoint
            cout<<vec[i]<<"\n";
        }
    }

    else{
        for(int i=test-1; i>=0; i--){
            cout<<vec[i]<<"\n";
        }
    }
 
    return 0;
}