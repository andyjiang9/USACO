#include <bits/stdc++.h>

using namespace std;

string alph, word;
int times = 0;
vector<int> hello;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> alph >> word;

    int counter = 0;
    while(counter < word.size()) {
        char letter = word[counter];

        for(int i = 0; i < alph.size(); i++) {
            if(counter >= word.size()) break;

            if(alph[i] == letter) {
                counter++;
                letter = word[counter];
            }
        }
        
        times++;
    }

    cout << times;
}