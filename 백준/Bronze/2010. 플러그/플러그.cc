#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	int N;
	cin >> N;
    
	int sum = 0;
    int num;
    
	while (N--) {
		cin >> num;
		sum += num - 1;
	}
	++sum;

	cout << sum << endl;

	return 0;
}