#include <bits/stdc++.h>

using namespace std;

ifstream fin("herding.in");
ofstream fout("herding.out");

int n;
int mini = 0;
int maxi = 0;
int cows[100005];
// 11001
int main() {
    fin >> n;
	int mincow = 1000000000;
	int maxcow = 0;
	for(int i = 0; i < n; i++){
		fin >> cows[i];
		mincow = min(mincow, cows[i]);
		maxcow = max(maxcow, cows[i]);
	}
	
	sort(cows, cows+n);

	int start = 0;
	int longest = 0;

	for(int end = 0; end < n; end++){
		while(start < end && cows[end]-cows[start] >= n)
			start++;
		longest = max(longest, end-start+1);
	}
	mini = n-longest;
    if(cows[n-2]-cows[0] == n-2 && cows[n-1]-cows[n-2] > 2) mini = 2;
    if(cows[n-1]-cows[1] == n-2 && cows[1]-cows[0] > 2) mini = 2;

	int gapbeg = cows[1]-cows[0]-1;
	int gapend = cows[n-1]-cows[n-2]-1;
	cout << maxcow << " " << mincow;
	maxi = maxcow-mincow+1-n-min(gapbeg, gapend);
	
	fout << mini << endl << maxi;
}