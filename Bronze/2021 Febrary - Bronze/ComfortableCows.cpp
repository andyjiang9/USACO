#include <bits/stdc++.h>
using namespace std;

int n;
pair<int,int> points[(int)1e5+2];
int grid[1002][1002];
bool three[1002][1002];
bool four[1002][1002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    int total = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        
        // 1 indexed
        grid[x+2][y+1]++; 
        grid[x][y+1]++;
        grid[x+1][y]++;
        grid[x+1][y+2]++;
        
        if(grid[x+2][y+1] == 3 && !three[x+2][y+1]) {
            total++; 
            three[x+2][y+1] = true;
        }
        if(grid[x][y+1] == 3) total++;
        if(grid[x+1][y] == 3) total++;
        if(grid[x+1][y+2] == 3) total++;


        if(grid[x+2][y+1] == 4 && !four[x+2][y+1]) {
            total--;
            four[x+2][y+1];
        }
        if(grid[x][y+1] == 4) total--;
        if(grid[x+1][y] == 4) total--;
        if(grid[x+1][y+2] == 4) total--;

        cout << total << "\n";
    }
}
