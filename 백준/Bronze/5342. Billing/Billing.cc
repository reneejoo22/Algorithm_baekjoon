//5342
#include<iostream>
#include<map>
#include<string>
using namespace std;


int main() {

    map<string, double> cost = {
        {"Paper", 57.99},
        {"Printer", 120.50},
        {"Planners", 31.25},
        {"Binders", 22.50},
        {"Calendar", 10.95},
        {"Notebooks", 11.20},
        {"Ink", 66.95}
    };

	double totalCost = 0.0;
    string s;

	while (true) {
		cin >> s;

        if (s == "EOI") {
            break;
        }
        totalCost += cost[s];
	}

    cout << "$" << totalCost << endl;
}