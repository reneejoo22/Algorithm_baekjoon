#include <iostream>
#include <string>

using namespace std;
char alpha[26];

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	int n;
	int	flag= 0;
	cin >> n;
	for (int i=0; i < n; i++)
	{
		cin >>s;
		alpha[(s[0] - 'a')]++;
	}
	for (int i=0; i < 26; i++)
	{
		if (alpha[i] >= 5)
		{
			cout << (char)(i+'a');
			flag = 1;
		}
	}
	if (!flag)
		cout << "PREDAJA";
}