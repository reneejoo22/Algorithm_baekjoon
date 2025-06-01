#include <iostream>
#include <string>
#include <cstdio>
 
using namespace std;
 
int main() {
 
    int a,b;
 
    int cnt1;
    int cnt2;
 
    while(scanf("%d%d", &a, &b)!=EOF){
        //테스트케이스의 종료에 대한 내용이 없으므로 EOF를 받으면 종료
        
        cnt1=0; // a~b 범위
        cnt2=0; // 한 숫자가 두 번 이상 들어있는 숫자 카운트
 
        for(int i=a; i<=b; i++){
            cnt1++;
            int cnt=0;
            int arr[10]={0};
            string str = to_string(i); 
            for(int i=0; i<str.length(); i++){
                cnt = str[i]-'0'; // str = 989 --> cnt int 9 int 8 int 9
                arr[cnt]++; // 989 = 0 0 0 0 0 0 0 0 1 2
            }
            for(int i=0; i<10; i++){
                if(arr[i]>=2){
                    cnt2+=1;
                    break; // 한 숫자가 두 번 이상 들어가는 숫자가 두 개 이상일 수 있기 때문에
                           // ex) 1100 1 두번 0 두번 break가 없으면 두번 카운트 된다.
                           // 그러므로 1번 카운트하고 break를 걸어준다.
                }
            }
        }
        cout<<cnt1-cnt2<<"\n";
    }
    return 0;
}
