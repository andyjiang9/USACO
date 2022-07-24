#include <bits/stdc++.h>

using namespace std;

int n, m, r;
int cows[100002];
pair<int,int> stores[100002];
int rent[100002];

bool cmp1(int a, int b){
    return a > b;
}
bool cmp2(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main(){
  ifstream fin("rental.in");
  ofstream fout("rental.out");

  fin >> n >> m >> r;

  for(int i = 0; i < n; i++){
    fin >> cows[i];
  }
  for(int i = 0; i < m; i++){
    fin >> stores[i].first >> stores[i].second;
  }
  for(int i = 0; i < r; i++){
    fin >> rent[i];
  }
  sort(cows, cows+n);
  sort(stores, stores+m, cmp2);
  sort(rent, rent+r, cmp1);

  long long sum = 0;
  int ind = -1;
  for(int i = 0; i < r; i++){
    if(i == n){
        break;
        ind--;
    }
    ind = i;
    sum += rent[i];
  }

  int j = 0;
  for(int i = ind+1; i < n; i++){
    int curr = cows[i];
    while(curr > 0){
      if(stores[j].first == 0){
        break;
      }
      if(stores[j].first < curr){
        sum += stores[j].first * stores[j].second;
        curr -= stores[j].first;
        j++;
      }else{
        sum += curr * stores[j].second;
        stores[j].first -= curr;
        curr = 0;
        if(stores[j].first == 0)
            j++;
      }
    }
  }

  long long maxsum = sum;
  for(int i = ind; i >= 0; i--){
    int curr = cows[i];
    sum -= rent[i];
    while(curr > 0){
      if(stores[j].first == 0){
        break;
      }
      if(stores[j].first < curr){
        sum += stores[j].first * stores[j].second;
        curr -= stores[j].first;
        j++;
      }else{
        sum += curr * stores[j].second;
        stores[j].first -= curr;
        curr = 0;
        if(stores[j].first == 0)
          j++;
      }
    }
    maxsum = max(maxsum, sum);
  }
  fout << maxsum;
}