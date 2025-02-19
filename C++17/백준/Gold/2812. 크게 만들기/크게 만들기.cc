//19941
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;  //자리수, 뺄 수 있는 수 
	
	string s;
	cin >> s;
	
	stack<char> st;
	stack<char>st2;

	int cnt = 0;
	for (int i = 0;i < s.size();i++) {
		while (!st.empty() && cnt < K && s[i] > st.top()) { // 스택이 비지 않았고
			//빼야하는 수가 K를 충족/ 현재 넣을 수가 stack의 top보다 클 때
			cnt++;
			st.pop();  //st에 아무 값도 안 들어 있는데 뭘 없애는겨
		}
		st.push(s[i]);
	}

	while (cnt < K) {  //만약 아직 K개를 삭제 못했으면 남은 개수를 채울 때까지 pop()
		cnt++;
		st.pop();
	}

	while (!st.empty()) {  //숫자 출력 순서 보정을 위해 보조 스택 st2 사용
		st2.push(st.top());
		st.pop();
	}
	while (!st2.empty())
	{
		cout << st2.top();
		st2.pop();
	}

}