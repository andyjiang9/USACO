#include <bits/stdc++.h>
using namespace std;

pair<int,int> bucket1;
pair<int,int> bucket2;
pair<int,int> bucket3;

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");

	fin >> bucket1.first >> bucket1.second;
    fin >> bucket2.first >> bucket2.second;
    fin >> bucket3.first >> bucket3.second;

	int count = 0;
    int difference;
    for(int i = 0; i < 100; i++) {
        if(i % 3 == 0) {
            if(bucket1.second + bucket2.second > bucket2.first){
                difference = bucket2.first-bucket2.second;
				bucket2.second = bucket2.first;
                bucket1.second -= difference;
			} else {
                bucket2.second += bucket1.second;
				bucket1.second = 0;
            }
        }else if(i % 3 == 1) {
            if(bucket2.second + bucket3.second > bucket3.first){
                difference = bucket3.first-bucket3.second;
				bucket3.second = bucket3.first;
                bucket2.second -= difference;
			} else {
                bucket3.second += bucket2.second;
				bucket2.second = 0;
            }
        }else{
            if(bucket3.second + bucket1.second > bucket1.first){
                difference = bucket1.first-bucket1.second;
				bucket1.second = bucket1.first;
                bucket3.second -= difference;
			} else {
                bucket1.second += bucket3.second;
				bucket3.second = 0;
            }
		}
    }
	fout << bucket1.second<<endl;
    fout << bucket2.second << "\n" << bucket3.second;
}