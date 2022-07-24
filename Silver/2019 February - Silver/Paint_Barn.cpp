#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int n, k;
int wall[1001][1001];

int main() {
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");

    fin >> n >> k;

    for(int i = 0; i < n; i++) {
        pair<int,int> bottomLeft, topRight;
        fin >> bottomLeft.first >> bottomLeft.second >> topRight.first >> topRight.second;

        bottomLeft.first++;
        bottomLeft.second++;
        topRight.first++;
        topRight.second++;

        wall[bottomLeft.first][bottomLeft.second]++;
        wall[bottomLeft.first][topRight.second]--;
        wall[topRight.first][bottomLeft.second]--;
        wall[topRight.first][topRight.second]++;
        
    }

    for(int i = 1; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            wall[i][j] += (wall[i-1][j] + wall[i][j-1]) - (wall[i-1][j-1]);
        }
    }
    
    int count = 0;
    for(int i = 1; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            if(wall[i][j] == k)
                count++;
        }
    }
    fout << count;
}
