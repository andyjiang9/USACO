#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
int a[(int)(2*1e5)];
ll ans = 0;
int last[(int)(2*1e5)];
map<ll, vector<pair<ll,ll>>> queries;
ll tree[(int)(2*1e5)];

ll query(ll r) {
    ll sum = 0;
    while (r > 0) {
      sum += tree[r];
      r -= r & -r;
    }
   return sum;
}
ll query(ll l, ll r) {
  return query(r) - query(l);
}
void update(ll i, ll d) {
  i++;
  while (i <= (int)(2*1e5)) {
    tree[i] += d;
    i += i & -i;
  }
}
void setone(ll i) {
  if (query(i, i+1) == 0)
    update(i, 1);
}
void setzero(ll i) {
  if (query(i, i+1) == 1)
    update(i, -1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    memset(last,-1,sizeof(last));
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int uniqueElements = 0;
    for(int i = 0; i < n; i++) {
        int pLoc = -1;
        bool idk = false;
        if (last[a[i]] != -1) {
            pLoc = last[a[i]];
            setzero(last[a[i]]);
            idk = true;
        } else {
            uniqueElements++;
        }
            
        last[a[i]] = i;
        setone(last[a[i]]);

        // query(j,i+1) gives you the number of elements from j to i
        if(idk == false) {
            ans += query(0,i+1)-1;
            //cout << "i:" << i << " " << query(0,i+1)-1 << "\n";
        } else {
            ans += query(pLoc,i+1)-1;
            //cout << "i:" << i << " " << query(pLoc,i+1)-1 << "\n";
        }
    }


    cout << ans << '\n';
}