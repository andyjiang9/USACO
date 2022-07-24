#include <bits/stdc++.h>
using namespace std;

int n, m, c;
long long maxProfit;
int cities[1001];
vector<int> adj[1001];
long long dp[2][1001];

int main() {
    ifstream fin("time.in");
    ofstream fout("time.out");

    cin >> n >> m >> c;

    for(int i = 1; i <= n; i++) {
        cin >> cities[i];
    }
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }

    
}