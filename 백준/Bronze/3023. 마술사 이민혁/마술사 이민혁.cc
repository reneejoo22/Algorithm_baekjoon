#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
char card[102][102];
int r, c;
int a, b;
void makeCard() {
    for (int i = 0; i < r; i++) {
        for (int j = c; j < 2 * c; j++) {
            card[i][j] = card[i][(c-1) - (j - c)];
        }
    }
    for (int i = r; i < 2 * r; i++) {
        for (int j = 0; j < 2 * c; j++) {
            card[i][j] = card[(r-1)-(i-r)][j];
        }
    }
}
void changeCard() {
    if (card[a][b] == '.') {
        card[a][b] = '#';
    }
    else {
        card[a][b] = '.';
    }
}
void printCard() {
    for (int i = 0; i < 2 * r; i++) {
        for (int j = 0; j < 2 * c; j++) {
            cout << card[i][j];
        }
        cout << endl;
    }
}
int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> card[i][j];
        }
    }
    cin >> a >> b;
    a--;
    b--;
    makeCard();
    changeCard();
    printCard();
}
