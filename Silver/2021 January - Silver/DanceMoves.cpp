#include <bits/stdc++.h>

using namespace std;

int n, k;
int initial[(int)1e5+1];
int endPos[(int)1e5+1];
set<int> adj[(int)1e5+1];
bool visited[(int)1e5+1];
int header[(int)1e5+1];

void dfs(int curr, int head) {
    if(curr != head) {
        visited[curr] = true;
        header[curr] = head;
        adj[head].insert(adj[curr].begin(),adj[curr].end());
        dfs(endPos[curr],head);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        initial[i] = i;
        adj[i].emplace(i);
    }

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        adj[initial[a]].emplace(b);
        adj[initial[b]].emplace(a);

        int temp = initial[a];
        initial[a] = initial[b];
        initial[b] = temp;
    }

    for(int i = 0; i < n; i++) {
        endPos[initial[i]] = i;
    }
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            header[i] = i;
            dfs(endPos[i],i);
        }
    }

    /*
    cout << "pos 0: ";
    for(int i : adj[0]) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "pos 1: ";
    for(int i : adj[1]) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "pos 2: ";
    for(int i : adj[2]) {
        cout << i << " ";
    }
    cout << "\n";

    
    cout << "pos 3: ";
    for(int i : adj[3]) {
        cout << i << " ";
    }
    cout << "\n";

    cout << "pos 4: ";
    for(int i : adj[4]) {
        cout << i << " ";
    }
    cout << "\n";
*/
    for(int i = 0; i < n; i++) {
        cout << adj[header[i]].size() << "\n";
    }
}