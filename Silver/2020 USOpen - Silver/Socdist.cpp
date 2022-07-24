
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, M;
pair<long,long> intervals[100001];

bool check(long dist) {
    long cowCount = 1;
    long previousPlacement = intervals[0].first;

    for(int i = 0; i < M; i++) {
        while(max(previousPlacement+dist,intervals[i].first) <= intervals[i].second) {
            previousPlacement = max(previousPlacement+dist,intervals[i].first);
            cowCount++;
        }
        if(cowCount >= N)
            return true;
    }

    return false;
}

int main() {
    ifstream fin("socdist.in");
    ofstream fout("socdist.out");

    fin >> N >> M;

    for(int i = 0; i < M; i++) {
        fin >> intervals[i].first;
        fin >> intervals[i].second;
    }

    sort(intervals,intervals+M);
    
    long low = 0;
    long high = 1000000000000000001;
    long ans = -1;

    while(low <= high) {
        long middle = (low+high) / 2;

        if(check(middle)) {
            ans = middle;
            low = middle+1;
        }
        else {
            high = middle-1;
        }
    }

    fout << ans;
}
