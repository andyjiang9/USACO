#include <bits/stdc++.h>

using namespace std;

int n;
int numRight = 0, numUp = 0;
vector<int> rightCows, upCows;
pair<int,int> pos[1001];
bool stopped[1001];
int ans[1001];

bool cmpUpCows(int a, int b) {
    return pos[a].first < pos[b].first;
}

bool cmpRightCows(int a, int b) {
    return pos[a].second < pos[b].second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        
        // puts right cows into right side and vise versa
        if(temp[0] == 'E') {
            rightCows.push_back(i);
            numRight++;
        } else {
            upCows.push_back(i);
            numUp++;
        }
        cin >> pos[i].first;
        cin >> pos[i].second;
    }

    sort(rightCows.begin(),rightCows.end(),cmpRightCows);
    sort(upCows.begin(),upCows.end(),cmpUpCows);

    for(int i : rightCows) {
        for(int j : upCows) {
            if(!stopped[j] && !stopped[i] && pos[i].first < pos[j].first && pos[i].second > pos[j].second) {
                if(pos[i].first + pos[i].second > pos[j].first + pos[j].second) {
                    stopped[j] = true;
                    ans[i] += (ans[j] + 1);
                } else if(pos[i].first + pos[i].second < pos[j].first + pos[j].second) {
                    stopped[i] = true;
                    ans[j] += (ans[i] + 1);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}