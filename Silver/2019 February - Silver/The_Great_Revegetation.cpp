#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int n, m;
vector<int> sadj[100001]; 
vector<int> dadj[100001];
int sim[100001];

bool dfs(int prev, int curr) {
    //prev is one or two
    //curr last node
    sim[curr] = prev;
    for(int i : sadj[curr]){
        if(sim[i] == sim[curr] || sim[i] == 0){
            if(sim[i] == 0)
                dfs(prev, i);
        }else
            return false;
    }
    for(int i : dadj[curr]) { 
        if(sim[i] != sim[curr] || sim[i] == 0){
            if(sim[i] == 0)
                dfs(3-prev, i);
        }else
            return false;
    }
    return true;
}

int main() {
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");

    fin >> n >> m;

    for(int i = 0; i < m; i++) {
        char tempChar;
        int temp1, temp2;
        fin >> tempChar >> temp1 >> temp2;
        if(tempChar == 'S') {
            sadj[temp1-1].push_back(temp2-1);
            sadj[temp2-1].push_back(temp1-1);
        }
        else {
            dadj[temp1-1].push_back(temp2-1);
            dadj[temp2-1].push_back(temp1-1);
        }
    }
    
    int cycles = 0;
    for(int i = 0 ; i < n; i++) {
        if(sim[i] == 0) {
            if(dfs(1,i) == false) {
                fout << 0;
                return 0;
            }
            cycles++;
        } 
    }
    
    fout << 1;
    for(int i = 0; i < cycles; i++) {
        fout << 0;
    }
    
}