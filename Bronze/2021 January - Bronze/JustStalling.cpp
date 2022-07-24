#include <bits/stdc++.h>

using namespace std;

int n;
int c[21], b[21], a[21];
long long ans = 0;

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(c,c+n);
    sort(b,b+n,cmp);

    // i is the cow
    for(int i = 0; i < n; i++) {
        int numPossible = 0;
        // j is the stall
        for(int j = 0; j < n; j++) {
            if(c[i] > b[j]) break;
            numPossible++;
        }
        a[i] = numPossible;
    }

    sort(a,a+n);
    for(int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    
}