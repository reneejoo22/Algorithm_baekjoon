#include <iostream>

using namespace std;

int main()

{

	int t, n, input;	cin >> t;

	for (int i = 0; i < t; i++)

	{

		cin >> n;

		int result = 0;

		int max = -1, min = 100;

		for (int j = 0; j < n; j++)

		{

			cin >> input;

			if (input < min)

				min = input;

			if (input > max)

				max = input;

		}

		result = (max - min) * 2;

		cout << result << endl;

	}

	return 0;

}