#include <bits/stdc++.h>

using namespace std;

const long long MOD = (long long)1e9+7;

int n, m, k;
pair<long long,long long> words[5005];
long long dp[5005];
long long rhymes[5005];
long long letters[30];

ifstream fin("poetry.in");
ofstream fout("poetry.out");
//find all possible combinations of lines
//if a line ends in a rhyme scheme then we add it to that 

//all the lines of a rhyme scheme ^ amount a patter occurs

long long binpow(long long base, long long exp){
	long long ans = 1;
	base %= MOD;
	
	while(exp > 0){
		if(exp % 2 == 1){
			ans = ((ans% MOD) * (base% MOD))% MOD;
		} 
		base = ((base% MOD)*(base% MOD))% MOD;
		exp/=2;
	}
	return ans% MOD;
}

int main(){
	fin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		fin >> words[i].first >> words[i].second;
	}
	for(int i = 0; i < m; i++){
		char temp;
		fin >> temp;
		letters[(int)temp - 65]++;
	}
	dp[0] = 1;
	//i represents syllable i am jeff
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < n; j++){
			if(i == k && i - words[j].first >= 0)
				rhymes[words[j].second] = ((rhymes[words[j].second] % MOD)+ (dp[i-words[j].first] % MOD)) % MOD;
			if(i - words[j].first >= 0){
				dp[i] = ((dp[i] % MOD) + (dp[i-words[j].first] % MOD) % MOD);
			}
		}
	}
	long long ways = 1;
	for(int i = 0; i < 26; i++){
		long long curr = 0;
		if(letters[i] > 0){
			for(int j = 0; j <= n; j++){
				if(rhymes[j] > 0){
					curr = ((curr % MOD) + (binpow(rhymes[j] % MOD, letters[i])))% MOD;
				}
			}
		}
		if(curr > 0)
			ways = ((ways % MOD) * (curr% MOD))% MOD;
		cout << curr << endl;
	}
	fout << ways;
}