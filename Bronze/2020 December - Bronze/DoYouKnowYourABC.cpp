#include <bits/stdc++.h>
using namespace std;
int n = 7;
int a[7];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a,a+n);
    cout << a[0] << " " << a[1] << " " << a[6]-a[0]-a[1];
}