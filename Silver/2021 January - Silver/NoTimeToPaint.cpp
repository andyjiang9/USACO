#include <bits/stdc++.h>

using namespace std;

int n, numQ;
string strFence;
int fence[(int)1e5+1];
pair<int,int> q[(int)1e5+1];
int s[(int)1e5+1];
int e[(int)1e5+1];
bool used[27];
int prevNum, currNum, ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> numQ;
    cin >> strFence;

    for(int i = 0; i < numQ; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        q[i].first = a;
        q[i].second = b;
    }

    for(int i = 0; i < n; i++) {
        fence[i] = ((int)toupper(strFence[i]))-64;
    }

    // precomputation
    // sweep from the front
    s[0] = 0;
    s[1] = 1;
    ans = 1;
    prevNum = fence[0];
    used[fence[0]] = true;
    for(int i = 1; i < n; i++) {
        currNum = fence[i];
        if(currNum > prevNum) {
            ans++;
        } else if(!used[currNum]) {
            ans++;

        } 
        for(int j = currNum; j <= 26; j++) {
            used[j] = false;
        }
        prevNum = currNum;
        used[currNum] = true;
        s[i+1] = ans;
    }
    
    // reset
    ans = 1;
    memset(used,false,sizeof(used));

    // sweep from the back
    e[n-1] = 0;
    e[n-2] = 1;
    prevNum = fence[n-1];
    used[fence[n-1]] = true;
    for(int i = n - 2; i >= 1; i--) {
        currNum = fence[i];
        if(currNum > prevNum) {
            ans++;
        } else if(!used[currNum]) {
            ans++;
        } 
        for(int j = currNum; j <= 26; j++) {
             used[j] = false;
        }
        prevNum = currNum;
        used[currNum] = true;
        e[i-1] = ans;
    }

    // go through each instance
    for(int i = 0; i < numQ; i++) {
        int a = q[i].first;
        int b = q[i].second;
        long long c = s[a] + e[b];
        cout << c << "\n";
    }

}