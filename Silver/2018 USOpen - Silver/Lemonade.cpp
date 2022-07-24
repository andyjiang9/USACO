#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

long long line[100001];
int ans = 0;

bool cmp(long long a, long long b) {
    return a > b;
}

int main() {
    ifstream fin("lemonade.in");
    ofstream fout("lemonade.out");

    int n;
    fin >> n;

    for(int i = 0; i < n; i++) {
        fin >> line[i];
    }
    sort(line,line+n,cmp);

    int i = 0;
    while(i < n && line[i] >= i) {
        i++;
        ans++;
    }

    fout << ans << "\n";
}