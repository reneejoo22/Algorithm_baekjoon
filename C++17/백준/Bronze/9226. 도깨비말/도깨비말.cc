#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
 
    while (1)
    {
        string word;
 
        cin >> word;
        if (word == "#") break;
        
        // 피그라틴어 만들기
        int start = 0;
        bool flag = 0;
        int word_len = (int)word.length();
        while (1)
        {
            if (start > word_len + 1)
            {
                flag = 1;
                break;
            }
            if (word[start] == 'a' || word[start] == 'e' || word[start] == 'i' || word[start] == 'o' || word[start] == 'u') break;
            else 
            {
                word += word[start];
                start++;
            }
        }
 
        // 모음이 하나도 안 발견된 경우
        if (flag)
        {
            for (int i = 0; i < word_len; i++)
            {
                cout << word[i];
            }
        }
        else 
        {
            int len = (int)word.length();
            for (int i = start; i < len; i++)
            {
                cout << word[i];
            }
        }
 
        cout << "ay\n";
    }
 
    return 0;
}
