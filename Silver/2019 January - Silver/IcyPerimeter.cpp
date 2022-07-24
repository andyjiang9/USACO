#include <bits/stdc++.h>

using namespace std;

int n;
int iceCream[1003][1003];
bool visited[1003][1003];
pair<int,int> info[1000*1000];
int maxA = 0;
int numTags = 0;
vector<int> bestOptions;

void dfs(int x, int y, int tag) {
    // each time we do a dfs, we can track the area and perimeter by making a
    // tagged value and store in an array of pairs the values of it's perimeter 
    // and area
    // if already visited, then return;
    if(visited[x][y] == true) {
        return;
    }
    // if not visited and is 1, then we add to area
    if(iceCream[x][y] == 1) {
        visited[x][y] = true;
        info[tag].first++;
    }
    // if it is a 0 value, then we add to perimeter
    if(iceCream[x][y] == 0) {
        info[tag].second++;
    }
    // dfs has to go through the blobs check up down left right
    if(iceCream[x][y] == 1) {
        dfs(x+1,y,tag);
        dfs(x-1,y,tag);
        dfs(x,y+1,tag);
        dfs(x,y-1,tag);
    }
}
/*
bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first > b.first) {
        return true;
    } 
    if(a.first == b.first) {
        if(a.second > b.second) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}
*/
int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> n;
    // input
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char temp;
            fin >> temp;
            if(temp == '#')
                iceCream[i][j] = 1;
            else 
                iceCream[i][j] = 0;
        }
    }

    // check if a location has a blob not visited
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(iceCream[i][j] == 1 && visited[i][j] == false) {
                // dfs
                dfs(i,j,numTags++);
                int area = info[numTags-1].first;
                int peri = info[numTags-1].second;
                if(area > maxA) {
                    maxA = area;
                    bestOptions.clear();
                    bestOptions.push_back(peri);
                } else if(area == maxA) {
                    bestOptions.push_back(peri);
                }
            }
        }
    }
    // sort array by first value, then second value
    sort(bestOptions.begin(),bestOptions.end());
    
    // print the very first blob's first and second value
    fout << maxA << " " << bestOptions.at(0);

}