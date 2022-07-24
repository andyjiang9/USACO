#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
pair<int,int> pos[(int)5e4+1];
int c[(int)5e4+1];
int lx, ly, hx, hy;
ll oneSquare = 0;
ll twoSquare = 0;
ll minDiff = INT_MAX;

ll s[(int)5e4+1];
ll e[(int)5e4+1];

bool cmpFront(int a, int b) {
    if(pos[a].first == pos[b].first) {
        return pos[a].second < pos[b].second;
    }
    return pos[a].first < pos[b].first;
}

bool cmpUp(int a, int b) {
    if(pos[a].second == pos[b].second) {
        return pos[a].first < pos[b].first;
    }
    return pos[a].second < pos[b].second;
}

int main() {    
    ifstream fin("split.in");
    ofstream fout("split.out");

    fin.tie(0);

    lx = INT_MAX; ly = INT_MAX; hx = INT_MIN; hy = INT_MIN;
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        c[i] = i;
        cin >> pos[i].first >> pos[i].second;

        if(pos[i].first > hx) hx = pos[i].first;
        if(pos[i].second > hy) hy = pos[i].second;
        if(pos[i].first < lx) lx = pos[i].first;
        if(pos[i].second < ly) ly = pos[i].second;
    }
    oneSquare = (ll)(hy - ly) * (ll)(hx - lx); 

    sort(c,c+n,cmpFront);
    lx = pos[c[0]].first; ly = pos[c[0]].second; hx = pos[c[0]].first; hy = pos[c[0]].first;
    
    for(int i = 0; i < n; i++) {
        int x = pos[c[i]].first;
        int y = pos[c[i]].second;

        if(x > hx) hx = x;
        if(y > hy) hy = y;
        if(x < lx) lx = x;
        if(y < ly) ly = y;

        s[i] = (ll)(hy - ly) * (ll)(hx - lx);
    }
    s[0] = 1;
    lx = pos[c[n-1]].first; ly = pos[c[n-1]].second; hx = pos[c[n-1]].first; hy = pos[c[n-1]].first;
    for(int i = n-1; i >= 0; i--) {
        int x = pos[c[i]].first;
        int y = pos[c[i]].second;

        if(x > hx) hx = x;
        if(y > hy) hy = y;
        if(x < lx) lx = x;
        if(y < ly) ly = y;

        e[i] = (ll)(hy - ly) * (ll)(hx - lx);
    }
    e[n-1] = 1;

    for(int i = 0; i < n; i++) {
        cout << s[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << e[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n-1; i++) {
        ll diff = oneSquare - s[i] + e[i+1];
        if(diff < minDiff)
            minDiff = diff;
    }

    cout << minDiff;
}