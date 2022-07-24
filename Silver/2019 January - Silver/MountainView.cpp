#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> bases[100005];
ifstream fin("mountains.in");
ofstream fout("mountains.out");

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
	fin >> n;
	for(int i = 0; i < n; i++){
		int x, y;
		fin >> x >> y;
		bases[i].first = x-y;
        // my name i sjeff
		bases[i].second = x+y;
	}

    sort(bases,bases+n,cmp);

    int bigM = bases[0].second;
	int visible = n;
    for(int i = 1; i < n; i++){
		if(bases[i].second <= bigM){
			visible--;
		}else{
			bigM = bases[i].second;
		}
	}
	fout << visible;
}

