#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[(int)1e5+2];
bool visited[(int)1e5+2];
long long minDays = 0;

void dfs(int node) {
    if(visited[node] == true)
        return;
    int numC = 0;

    if(node == 1)
        numC = adj[node].size();
    else
        numC = adj[node].size()-1;

    long long cowsInfected = 1;
    visited[node] = true;

    while(cowsInfected <= numC) {
        cowsInfected *= 2;
        minDays++;
    }

    for(int neighbor : adj[node]) {
        if(visited[neighbor] == false) {
            minDays++;
            dfs(neighbor);
        }
    }
}

int main() {
    // take in imputs and store in adj list
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int farmA, farmB;
        cin >> farmA >> farmB;

        adj[farmA].push_back(farmB);
        adj[farmB].push_back(farmA);
    }

    // perform dfs starting at node 1:
    /*
    1 - We start with 1 cow at a node (node 1)
    2 - We double it until we get above adj.size() & every time we +1 day
    3 - And then we can move onto next nodes and +1 day with each movement
    4 - We mark the node as visited
    */
   dfs(1);

   // Now we print out the min days
   cout << minDays;
}
