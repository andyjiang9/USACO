#include <bits/stdc++.h>

using namespace std;

int c, n;
map<int,int> chickens;
pair<int,int> cows[100000];

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second < b.second;
}

int main(){
	ifstream fin("helpcross.in");
	ofstream fout("helpcross.out");
	fin >> c >> n;
	for(int i = 0; i < c; i++){
		int temp;
		fin >> temp;
		chickens[temp]++;
	}
	for(int i = 0; i < n; i++)
		fin >> cows[i].first >> cows[i].second;

	sort(cows, cows+n, cmp);

	int ans = 0;

	for(int i = 0; i < n; i++){
		int start = cows[i].first;
		int end = cows[i].second;

		int temp = (*chickens.lower_bound(start)).first;
		if(temp <= end && (chickens.lower_bound(start) != chickens.end())){
			ans++;
			chickens[temp]--;
			if(chickens[temp] == 0)
				chickens.erase(temp);
		}

	}
	fout << ans;

}