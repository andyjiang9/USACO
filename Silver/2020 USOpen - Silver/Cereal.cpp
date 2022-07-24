
#include <iostream>
#include <fstream>

using namespace std;

int N, M;
int cerealTaken[100001];
pair<int,int> preferance[100000];
int ans[100000];

int main() {
    ifstream fin("cereal.in");
    ofstream fout("cereal.out");

    fin >> N >> M;

    for(int i = 0; i < N; i++) {
        fin >> preferance[i].first;
        fin >> preferance[i].second;
    }

    int count = 0;
    for(int i = N-1; i >= 0; i--) {
        int j = i;
        int curPosCereal = preferance[i].first;

        while(true) {
            if(cerealTaken[curPosCereal] == 0) {
                cerealTaken[curPosCereal] = j;
                count++;
                break;
            } 
            else if(cerealTaken[curPosCereal] < j) {
                break;
            }
            else {
                int posCow = cerealTaken[curPosCereal];
                cerealTaken[curPosCereal] = j;
                if(curPosCereal == preferance[posCow].second)
                    break;
                j = posCow;
                curPosCereal = preferance[posCow].second;
            }
        }
        ans[i] = count;
    }

    for(int i = 0; i < N; i++) {
        fout << ans[i] << "\n";
    }
}