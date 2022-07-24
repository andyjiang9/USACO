#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int N;
pair<int,int> particles[100000]; 
int minlowbound[100000];
int maxhighbound[100000];

bool cmp(pair<int,int> a, pair<int, int> b) {
    if(a.first == b.first) 
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ifstream fin("moop.in");
    ofstream fout("moop.out");
    fin >> N;
    for(int i = 0; i < N; i++) {
        fin >> particles[i].first >> particles[i].second;
    }
    
    sort(particles,particles+N,cmp);
    
    int minbound = 1000000000;
    for(int i = 0; i < N; i++) {
        minbound = min(minbound,particles[i].second); 
        minlowbound[i] = minbound;
    }
    
    int maxbound = -1000000000;
    for(int i = N-1; i >= 0; i--) {
        maxbound = max(maxbound,particles[i].second);
        maxhighbound[i] = maxbound;
    }
    
    int count = 1;
    for(int i = 0; i < N-1; i++){
        if(minlowbound[i] > maxhighbound[i+1])
            count++;
    }

    fout << count;
    
}