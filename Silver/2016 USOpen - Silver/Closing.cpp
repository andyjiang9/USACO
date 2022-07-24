#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[3001];
bool closed[3001];
bool visited[3001];

void dfs(int node) {
    if(visited[node] == true)
        return;

    visited[node] = true;

    for(int i = 0; i < adj[node].size(); i++) {
        dfs(adj[node].at(i));
    }
}

void reset() {
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
    }
}

bool check() {
    for(int i = 1; i <= n; i++) {
        if(visited[i] == false && closed[i] == false) {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");
    
    fin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    int count = 1;
    for(int i = 0; i < n; i++) {
        while(closed[count] == true)
            count++;

        dfs(count);

        if(check())
            fout << "YES" << "\n";
        else
            fout << "NO" << "\n";
        
        int closedBarn;
        fin >> closedBarn;
        adj[closedBarn].clear();
        closed[closedBarn] = true;
        reset();
    }
}