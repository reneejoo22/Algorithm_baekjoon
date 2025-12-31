// 14501
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int day;
static vector<pair<int, int>>v;
static bool except[15];
int ans = -1;
void dp(int startDay, int tmpSum);

int main() {
	
	cin >> day;

	v.resize(day);
	for (int i = 0; i < day; i++) {
		cin >> v[i].first >>v[i].second;
	}

	dp(0, 0);
    cout << ans << endl;
}


void dp(int startDay, int tmpSum) {

	if (startDay > day)
	{
		return;
	}
	ans = max(ans, tmpSum);

	for (int i = startDay; i < v.size(); i++)
	{
		dp(i + v[i].first, tmpSum + v[i].second);
	}
}