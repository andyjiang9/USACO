#include <bits/stdc++.h>

using namespace std;

int t, a, b;
bool dp[2][(int)5e6+2];

int main() {
    ifstream fin("feast.in");
    ofstream fout("feast.out");

    fin >> t >> a >> b;

    dp[0][0] = true;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j <= t; j++) {
            if(!dp[i][j])
                continue;
            if(j + a <= t) {
                dp[i][j+a] = true;
            }
            if(j + b <= t) {
                dp[i][j+b] = true;
            }
            if(i == 0) {
                dp[i+1][j/2] = true;
            }
        }
    }   

    int temp = t;
    while(!dp[1][temp]) {
        temp--;
    }

    fout << temp;
}