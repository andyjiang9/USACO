#include <bits/stdc++.h>

using namespace std;

int n;
int grid[1003][1003];
int rows[2][1003];
int columns[1003][2];
int bestNum = -1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            rows[i%2][j] += grid[i][j];
            columns[i][j%2] += grid[i][j];
        }
    }

    // find the best combo for the row patterns
    int num = 0;
    for(int i = 0; i < n; i+=2) {
        num += (rows[0][i] + rows[1][i]);
    }
    bestNum = max(num,bestNum);

    num = 0;
    for(int i = 1; i < n; i+=2) {
        num += (rows[0][i] + rows[1][i]);
    }
    bestNum = max(num,bestNum);

    num = 0;
    for(int i = 0; i < n; i++) {
        num += max(rows[0][i],rows[1][i]);
    }
    bestNum = max(num,bestNum);

    // find the best combo for the column patterns
    num = 0;
    for(int i = 0; i < n; i+=2) {
        num += (columns[i][0] + columns[i][1]);
    }
    bestNum = max(num,bestNum);

    num = 0;
    for(int i = 1; i < n; i+=2) {
        num += (columns[i][0] + columns[i][1]);
    }
    bestNum = max(num,bestNum);

    num = 0;
    for(int i = 0; i < n; i++) {
        num += max(columns[i][0],columns[i][1]);
    }
    bestNum = max(num,bestNum);

    cout << bestNum;
}