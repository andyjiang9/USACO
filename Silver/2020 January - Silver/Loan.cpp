#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef long long ll;

ll n, k, m;
ll ans = -1;

bool check(ll x) {

    ll gallonsGiven = 0;
    
    ll day = 0;
    ll y = 0;
    while(gallonsGiven < n && day < k) {
        y = (n-gallonsGiven)/x;

        if(y < m) 
            break;

        gallonsGiven += y;
        day++;
    }
    
    gallonsGiven += m * (k-day);
    
    
    return (gallonsGiven >= n);
    
}

int main() {
    ifstream fin("loan.in");
    ofstream fout("loan.out");

    fin >> n >> k >> m;
    ll high = 2000000000001;
    ll low = 0;
    
    while(low < high) {
        ll mid = (high+low+1)/2;
        if(check(mid)) {
            low = mid;
        } else {
            high = mid-1;
        }
    }
    
    fout << low;
}