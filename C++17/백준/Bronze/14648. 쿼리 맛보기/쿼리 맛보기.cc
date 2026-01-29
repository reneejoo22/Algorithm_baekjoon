#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include<numeric>

// https://www.acmicpc.net/problem/3252

class CQueryFirstTaste
{
private:
	/* 수열 사이즈 */ 
	int sequenceSize;
	/* 질의 사이즈 */ 
	int querySize; 
	/* 수열 */ 
	long* numberSequenceArray;

public:
	CQueryFirstTaste()
	{
	}

	~CQueryFirstTaste()
	{
		delete[] numberSequenceArray;
	}

	void getInputFromUser()
	{
		getSequenceAndQuerySizeInput();
		getSequenceArrayInput();
	}

	void getSequenceAndQuerySizeInput()
	{ 
		std::string inputStr; 
		std::getline(std::cin, inputStr); 
		std::stringstream ss(inputStr); 
		ss >> sequenceSize;
		ss >> querySize;
	}

	void getSequenceArrayInput()
	{
		numberSequenceArray = new long [sequenceSize];

		std::string inputStr;
		std::getline(std::cin, inputStr);
		std::stringstream ss(inputStr);

		for (int i = 0; i < sequenceSize; i++)
		{
			long tempVal;
			ss >> tempVal;
			numberSequenceArray[i] = tempVal;
		}
	}

	void getQueries()
	{
		for (int i = 0; i < querySize; i++)
		{
			std::string inputStr;
			std::getline(std::cin, inputStr);
			std::stringstream ss(inputStr);

			long tempVal;
			ss >> tempVal;

			switch (tempVal)
			{
			case 1:
			{
				int a;
				int b;
				ss >> a;
				ss >> b;
				queryProcess1(a, b);
				break;
			}
			case 2:
			{
				int a;
				int b;
				int c;
				int d;
				ss >> a;
				ss >> b;
				ss >> c;
				ss >> d;
				queryProcess2(a, b, c, d);
				break;
			}
			default:
				std::cout << "hello";
				break;
			}
		}
	}

	void queryProcess1(const long a, const long b)
	{
		long sum = 0;

		/* 합을 출력한다.*/
		for (int i = a-1; i < b; i++)
		{
			sum = sum + numberSequenceArray[i];
		}
		std::cout << sum << "\n";


		/* index a 값과 index b 의 값을 교환한다.*/
		std::swap(numberSequenceArray[a - 1], numberSequenceArray[b - 1]);
	};

	void queryProcess2(const long a, const long b, const long c, const long d)
	{
		

		/* 구간합1*/

		long sum1 = 0;

		for (int i = a - 1; i < b; i++)
		{
			sum1 = sum1 + numberSequenceArray[i];
		}
		
		/* 구간합2*/

		long sum2 = 0;

		for (int i = c - 1; i < d; i++)
		{
			sum2 = sum2 + numberSequenceArray[i];
		}

		/* 결과 */
		std::cout << (sum1 - sum2) << "\n";
	};
};

int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	CQueryFirstTaste* cQueryFirstTaste = new CQueryFirstTaste();

	cQueryFirstTaste->getInputFromUser();

	cQueryFirstTaste->getQueries();

	//cBingo->printMyMap();


}