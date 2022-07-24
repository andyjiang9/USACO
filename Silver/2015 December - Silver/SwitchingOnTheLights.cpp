#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int n, m;
bool rooms[102][102];
bool visited[102][102];
vector<pair<int,int>> lights[102][102];
int roomsIlluminated = 0;

void floodfill(int a, int b) {
    // if the room has already been visited or the room is dark
    if(visited[a][b] == true || rooms[a][b] == false) {
        return;
    }
    visited[a][b] = true;
    
    for(int i = 0; i < lights[a][b].size(); i++) {
        pair<int,int> otherRoom = lights[a][b].at(i);

        rooms[otherRoom.first][otherRoom.second] = true;
        if(visited[otherRoom.first][otherRoom.second] == false)
            floodfill(otherRoom.first,otherRoom.second);
    }
    floodfill(a-1,b);
    floodfill(a+1,b);
    floodfill(a,b-1);
    floodfill(a,b+1);
}

int main() {
    ifstream fin("lightson.in");
    ofstream fout("lightson.out");

    fin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x, y, a ,b;

        fin >> x >> y >> a >> b;

        lights[x][y].push_back(make_pair(a,b));
    }

    rooms[1][1] = true;
    floodfill(1,1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(rooms[i][j] == true)
                roomsIlluminated++;
        }
    }


    fout << roomsIlluminated;
}