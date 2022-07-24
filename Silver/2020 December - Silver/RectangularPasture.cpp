#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
pair<int,int> points[2501];
int ps[2502][2502];

bool ycmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int rsum(int x1, int y1, int x2, int y2) {
    return ps[x2+1][y2+1] - ps[x2+1][y1] - ps[x1][y2+1] + ps[x1][y1];
}

int main() {
    // take in the input
    cin >> n;
    for(int i = 0; i < n; i++) {
         cin >> points[i].first;
        cin >> points[i].second;
    }
    // compression of the x
    sort(points,points+n);
    for(int i = 0; i < n; i++) {
        points[i].first = i+1;
    }
    // compression of the y 
    sort(points,points+n,ycmp);
    for(int i = 0; i < n; i++) {
        points[i].second = i+1;
    }

    // make the 2d prefix sum initial
    for(int i = 0; i < n; i++) {
        ps[points[i].first][points[i].second] = 1;
    }
    // do a complete walkthrough
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

    // how does this work????????????
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int x1 = min(points[i].first,points[j].first) - 1;
            int x2 = max(points[i].first,points[j].first) - 1;
            ans += rsum(0,i,x1,j) * rsum(x2,i,n-1,j);
        }
    }
    cout << ans + 1;

}