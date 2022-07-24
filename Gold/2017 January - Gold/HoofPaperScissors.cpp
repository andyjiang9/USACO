#include <bits/stdc++.h>
using namespace std;

int n, k;
int farmer[(int)1e5+1];
int dp[(int)1e5+1][21][3];

// Rock = 0, Paper = 1, Scissors = 2

int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    fin >> n >> k;
    for(int i = 0; i < n; i++) {
        char temp;
        fin >> temp;
        if(temp == 'H') farmer[i] = 0;
        if(temp == 'P') farmer[i] = 1;
        if(temp == 'S') farmer[i] = 2;
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int state = 0; state < 3; state++) {
                if(i != 0) {
                    if(j > 0)
                        dp[i][j][state] = max(max(dp[i-1][j-1][(state+1)%3],dp[i-1][j-1][(state+2)%3]),dp[i-1][j][state]) + (farmer[i-1] == state ? 1 : 0);
                    else 
                        dp[i][j][state] = dp[i-1][j][state] + (farmer[i-1] == state ? 1 : 0);
                }
            }
        }
    }

    fout << max(max(dp[n][k][0],dp[n][k][1]),dp[n][k][2]);
}