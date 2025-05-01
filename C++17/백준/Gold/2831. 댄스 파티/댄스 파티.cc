// 2831
#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> male_pos;vector<int> male_neg;
    vector<int> female_pos;vector<int> female_neg;


    int num;
    for (int i = 0;i < n;i++) {
        cin >> num;
        if (num < 0) {
            male_neg.push_back(abs(num));
        }
        else {
            male_pos.push_back(num);
        }
    }
    for (int i = 0;i < n;i++) {
        cin >> num;
        if (num < 0) {
            female_neg.push_back(abs(num));
        }
        else {
            female_pos.push_back(num);
        }
    }

    //오름 정렬
    sort(male_pos.begin(), male_pos.end(), greater<int>());
    sort(male_neg.begin(), male_neg.end(), greater<int>());
    sort(female_pos.begin(), female_pos.end(), greater<int>());
    sort(female_neg.begin(), female_neg.end(), greater<int>());

    int cnt = 0;
    int i = 0, j = 0;
    while (i < male_pos.size() && j < female_neg.size()) {
        if (male_pos[i] < female_neg[j]) {
            cnt++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }


    i = 0; j = 0;
    while (i < female_pos.size() && j < male_neg.size()) {
        if (female_pos[i] < male_neg[j]) {
            cnt++;
            i++;
            j++;
        }

        else {
            i++;
        }
    }

    cout << cnt;


}