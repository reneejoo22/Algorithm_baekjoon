#include<iostream>
#include<cstdlib>
using namespace std;

int main() {

	int x, y, xw, yw, xh, yh;
	cin >> x >> y;
	//11 33
	
	xw = (x - 1) / 4;	//2
	yw = (y - 1) / 4;	//8

	xh = (x - 1) % 4;	//2
	yh = (y - 1) % 4;	//0

	cout << abs(xw - yw) + abs(xh - yh);
}