#include <bits/stdc++.h>

using namespace std;

int n;
int grid[251][251];
bool visited[251][251];
bool visitedtemp[251];
int regsizes[1000001];
int markers[251][251];
int markersid[10000001];
int temp = 0;

void dfs(int i, int j, int id, int curr){
    if(i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || grid[i][j] != curr)
        return;
    visited[i][j] = true;
    markers[i][j] = id;

    regsizes[id]++;
    markersid[id] = curr;
    dfs(i+1, j, id, curr);
    dfs(i-1, j, id, curr);
    dfs(i, j+1, id, curr);
    dfs(i, j-1, id, curr);
}

void dfs2(int i, int j, int curr, int curr2){
    if(i < 0 || i >= n || j < 0 || j >=n || (grid[i][j] != curr2 && grid[i][j] != curr) || visited[i][j])
        return;
    visited[i][j] = true;
    temp++;
    dfs2(i+1,j,curr,curr2);
    dfs2(i-1,j,curr,curr2);
    dfs2(i,j+1,curr,curr2);
    dfs2(i,j-1,curr,curr2);
}

void dfs3(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >=n || !visited[i][j])
        return;
    visited[i][j] = false;
    dfs3(i+1,j);
    dfs3(i-1,j);
    dfs3(i,j+1);
    dfs3(i,j-1);
}

int main() {
    ifstream fin("multimoo.in");
    ofstream fout("multimoo.out");

    fin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            fin >> grid[i][j];

    int id = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!visited[i][j])
                dfs(i, j, id++, grid[i][j]);
    int maxi = -1;
    for(int i = 1; i < id; i++){
        maxi = max(regsizes[i], maxi);
    }
    for(int i = 0; i < n; i++){
            visitedtemp[i] = false;

    }
    fout << maxi << endl;
    int maxi2 = -1;
    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
				if(n*n == maxi2)
	                	break;
	            if(i > 0){
	                dfs2(i, j, grid[i][j], grid[i-1][j]);
	                maxi2 = max(maxi2, temp);
	                temp = 0;
	                dfs3(i,j);
	            }
	        }
    }
    fout << maxi2;
}