#include <iostream>
#include <string>
#include <vector>
using namespace std;
int abs(int a, int b)
{
	return a < b ? (b - a) : (a - b);
}
int main(void)
{
	int size = 4;
	vector<string> arr(4);
	for (int i = 0; i < size; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (arr[i][j] != '.')
				ans += abs(i, (arr[i][j] - 'A') / 4)+abs(j, (arr[i][j] - 'A') % 4);
	cout << ans;
}
