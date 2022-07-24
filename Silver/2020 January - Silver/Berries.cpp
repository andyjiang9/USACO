#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n, k;
int trees[1001];
int maxTree = -1;
int ans = 0;
int basketSimulator[1001];

int main() {
    ifstream fin("berries.in");
    ofstream fout("berries.out");

    fin >> n >> k;

    for(int i = 0; i < n; i++) {
        fin >> trees[i];
        
        if(trees[i] > maxTree)
            maxTree = trees[i];
    }

    for(int i = 1; i <= maxTree; i++) {
        for(int j = 0; j <= maxTree; j++) {
            basketSimulator[j] = 0;
        }
        
        for(int j = 0; j < n; j++) {
            int num = trees[j]/i;
            int leftover = trees[j] % i;
            
            basketSimulator[i] += num;
            if(leftover > 0)
                basketSimulator[leftover]++;
        }


        
        int basketsGiven = 0;
        int track = i;
        while(basketsGiven < k/2 && track > 0) {
            if(basketSimulator[track] > 0) { 
                basketsGiven++;
                basketSimulator[track]--;
            } else {
                track--;
            }
        }

        int tempAns = 0;
        while(track > 0 && basketsGiven < k) {
            if(basketSimulator[track] > 0) {
                tempAns += track;
                basketSimulator[track]--;
                basketsGiven++;
            } else {
                track--;
            }
        }

        if(tempAns > ans) {
            cout << ans << endl;
            ans = tempAns;
        }
    }

    fout << ans;
}