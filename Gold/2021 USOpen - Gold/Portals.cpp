#include <bits/stdc++.h>

using namespace std;

/*
int dsu[1001];

int find(int i) {
    if(dsu[i] == i) 
        return i;
    dsu[i] = find(dsu[i]);
    return dsu[i];
}

void merge(int i, int j) {
    dsu[find(j)] = find(i);
}
*/


int n, ans;
int cost[(int)4e5+1];
int cc[(int)4e5+1];
vector<pair<int,pair<int,int>>> bAdj;
map<int,vector<int>> edges;
vector<int> mapUsed;
vector<int> adj[(int)4e5+1];
int dsu[(int)4e5+1];

int find(int i) {
    if(dsu[i] == i) 
        return i;
    dsu[i] = find(dsu[i]);
    return dsu[i];
}

void merge(int i, int j) {
    dsu[find(j)] = find(i);
}

void dfs(int node, int flag) {
    if(cc[node] == 0) {
        cc[node] = flag;
        for(int nei : adj[node]) {
            dfs(nei,flag);
        }
            
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        edges[a].push_back(2*i);
        edges[b].push_back(2*i);
        edges[c].push_back(2*i+1);
        edges[d].push_back(2*i+1);
        mapUsed.push_back(a);
        mapUsed.push_back(b);
        mapUsed.push_back(c);
        mapUsed.push_back(d);
    }

    for(int i : mapUsed) {
        int a = edges[i].at(0);
        int b = edges[i].at(1);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int flag = 1;
    for(int i = 2; i <= 2*n+1; i++) {
        if(cc[i] == 0) {
            dfs(i,flag);
            flag++;
        }
    }

    for(int i = 2; i <= 2*n+1; i += 2) {
        bAdj.push_back({cost[i/2],{cc[i],cc[i+1]}});
    }
    sort(bAdj.begin(),bAdj.end());

    for(int i = 1; i < flag; i++) {
        dsu[i] = i;
    }

    for(int i = 0; i < (int)bAdj.size(); i++) {
        if(find(bAdj[i].second.first) != find(bAdj[i].second.second)) {
            merge(bAdj[i].second.first,bAdj[i].second.second);
            ans += bAdj[i].first;
        }
        
    }
    cout << ans;
}