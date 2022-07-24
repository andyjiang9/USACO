#include <bits/stdc++.h>

using namespace std;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

int n;
int cows[(int)1e5+1];
int t[(int)2e5+2];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main() {
    fin >> n;
    for(int i = 0; i < n; i++) {
		fin >> cows[i];
        cows[i]--;
    }

	int ind = n-1;
    t[cows[n-1]+n]++;
    for(int i = n-1; i > 0; i--) {
		if(cows[i] < cows[i-1]) {
			ind = i;
			break;
		}else{
			cout << "hi" << endl;
			t[cows[i-1]+n] = 1;
		}
    }
	for(int i = 0; i < 2*n; i++)  cout << t[i] << " ";
	build();

    fout << ind << "\n";

	//gives number of cows before it dub
	for(int i = 0; i < ind; i++){
		int notSorted = ind-i;
        int frontCow = cows[i];
        int dist = query(0,frontCow);

        modify(frontCow,1);
        if(i == ind-1) fout << notSorted + dist - 1;
        else fout << notSorted + dist - 1 << " ";
        

	}

    //for(int i = 0; i < 2*n; i++)  cout << t[i] << " ";
    
}