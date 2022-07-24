#include <bits/stdc++.h>

using namespace std;

int n, w;
int cows[251];
int weights[251];
int talents[251];
double dp[251];

int main() {
    ifstream fin("talent.in");
    ofstream fout("talent.out");

    fin >> n >> w;
    for(int i = 0; i < n; i++) {
        cows[i] = i;
        cin >> weights[i] >> talents[i];
    }

    
}