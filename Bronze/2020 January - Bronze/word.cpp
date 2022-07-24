#include <bits/stdc++.h>

using namespace std;

int n, k;
string words[101];

int main() {
    ifstream fin("word.in");
    ofstream fout("word.out");

    fin >> n >> k;

    for(int i = 0; i < n; i++) {
        fin >> words[i];
    }

    int i = 0;
    int counter = 0;
    while(i < n) {

        counter = 0;

        string word = words[i];
        int lengthOfWord = word.size();
        counter += lengthOfWord;
        fout << word;
        i++;

        while(counter + words[i].size() <= k && i < n) {
            word = words[i];
            lengthOfWord = word.size();
            if(counter + lengthOfWord > k) {
                i--;
                break;
            }
            counter += lengthOfWord;
            fout << " " << word;
            i++;
        }

        if(i < n)
            fout << "\n";
    }
}