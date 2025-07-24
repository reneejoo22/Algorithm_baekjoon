#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
string s;
string nums[11] = { "zero" ,"one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" };
vector<pair<string ,int>> ans;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> M >> N;
	
	for (int i = M; i <= N; i++)
	{
		if (i >= 10)
		{
			s = nums[i/10] + " " + nums[i%10];
			ans.push_back({ s,i });
		}
		else
		{
			s = nums[i % 10];
			ans.push_back({ s,i });
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].second << " ";
		if (i % 10 == 9) cout << '\n';
	}

}