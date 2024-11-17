#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
    string word;
    cin >> word;
 
    int count = 0;
    int len = word.length();
    for (int i = 0; i < len; i++){
        if (word[i] >= 'a' && word[i] <= 'z'){
            count += (int)(word[i] - 'a' + 1);
        }
        else if (word[i] >= 'A' && word[i] <= 'Z'){
            count += (int)(word[i] - 'A' + 27);
        }
    }
 
    bool flag = 0;
    for (int i = 2; i * i <= count; i++){
        if (count % i == 0){
            flag = 1;
            break;
        }
    }
 
    if (flag){
        cout << "It is not a prime word.";
    }
    else cout << "It is a prime word.";

    return 0;
}
