
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
 
    string str;
    cin>>str;
 
    vector<char> vec;
 
    for(int i=0; i<str.length(); i++){
        if(str[i]=='-'){
            vec.push_back(str[i+1]);
        }
    }

    cout<<str[0];

    for(int i=0; i<vec.size(); i++){
        cout<<vec[i];
    }
    return 0;
}
