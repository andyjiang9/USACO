#include<bits/stdc++.h>

using namespace std;

int n, numQ;
int a, b;
string fenceStr;
int fence[(int)1e5+1];
bool changed;
int total;
char allChars[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> numQ >> fenceStr;

    for(int i = 0; i < n; i++) {
        fence[i] = fenceStr[i];
    }

    for(int i = 0; i < numQ; i++) {
        cin >> a >> b;
        a--; b--;

        total = 0;
        changed = false;
        for(char c : allChars) {
            changed = false;

            for(int j = 0; j < n ; j++) {

                if(fence[j] < c || a <= j && j <= b) {
                    changed = false;
                } else if(fence[j] == c) {
                    if(!changed) {
                        changed = !changed;
                        total += 1;
                    } else {
                        continue;
                    }

                }

            }

        }

        cout << total << "\n";
    }

}