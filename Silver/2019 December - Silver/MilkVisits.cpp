#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100005];
vector<int> adj[100005];
int visited[100005];

void dfs(int curr, int marker, int type){
	for(int i : adj[curr]){ 
		if(visited[i] == -1 && arr[i] == type){
			visited[i] = marker;
			dfs(i, marker, type);
		}
	}

}

int main(){
	ifstream fin("milkvisits.in");
	ofstream fout("milkvisits.out");

	fin >> n >> m;
	string temp;
	fin >> temp;
	for(int i = 0; i < n; i++){
		if(temp.at(i) == 'H')
			arr[i] = 1;
		else
			arr[i] = 2;
	}

	for(int i = 0; i < n-1; i++){
		int u, v;
		fin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}

	for(int i = 0; i < n; i++){
		visited[i] = -1;
	}
	int marker = 1;
	for(int i = 0; i < n; i++){
		if(visited[i] == -1 && arr[i] == 1){
            visited[i] = marker;
			dfs(i, marker++,1);
		}
        else if(visited[i] == -1 && arr[i] == 2) {
            visited[i] = marker;
            dfs(i,marker++,1);
        }
	}

	for(int i = 0; i < m; i++){
		int a, b;
		string temp;
		fin >> a >> b;
		fin >> temp;
		a--; b--;
		if(visited[a] != visited[b])
            fout << 1;
        else {
            if((temp.at(0) == 'H' && arr[i] == 1) || (temp.at(0) == 'G' && arr[i]== 2)) {
                fout << 1;
            }
            else {
                fout << 0;
            }
        }   
    }
}