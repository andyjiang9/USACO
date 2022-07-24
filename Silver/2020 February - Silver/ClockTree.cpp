#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n;
int times[2500];
int temptimes[2500];
vector<int> graph[2500];

int dfs(int curr, int parent) {
    for(int i = 0; i < graph[curr].size(); i++) {
        if(graph[curr].at(i) != parent) {
            temptimes[graph[curr].at(i)]++;
            temptimes[curr] += 12 - dfs(graph[curr].at(i), curr);
            temptimes[curr] = (temptimes[curr]-1) % 12 +1;
        }
    }
    temptimes[parent]++;
    return temptimes[curr];
}

int main() {
    ifstream fin("clocktree.in");
    ofstream fout("clocktree.out"); 

    fin >> n;
    for(int i = 0; i < n; i++) {
        fin >> times[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int room1, room2;
        fin >> room1 >> room2;
        graph[room1-1].push_back(room2-1);
        graph[room2-1].push_back(room1-1);
    }
    
    int total = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temptimes[j] = times[j];
        }

        dfs(i, -1);
        for(int i = 0; i < n; i++){
            cout << temptimes[i] << " ";
        }
        cout << "\n";

        if(temptimes[i] == 12 || temptimes[i] == 1)
            total++;
    }
    fout << total;
}