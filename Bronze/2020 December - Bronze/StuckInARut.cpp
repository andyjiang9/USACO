#include <bits/stdc++.h>

using namespace std;

int n;
char direction[51];
pair<int,int> location[51];
int cows[51];
int ans[51];
bool stopped[51];
int rightCows = 0;

bool cmp(int a, int b) {
    if(direction[a] != direction[b]) {
        return direction[a] == 'E';
    }
    return location[a].first + location[a].second < location[b].first + location[b].second;
}

bool cmpRight(int a, int b) {
    return location[a].second < location[b].second;
}

bool cmpUp(int a, int b) {
    return location[a].first < location[b].first;
}


int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cows[i] = i;
    }

    for(int i = 0; i < n; i++) {
        string temp;
        int x, y;
        cin >> temp >> x >> y;

        direction[i] = temp[0];
        location[i].first = x;
        location[i].second = y;
        if(direction[i] == 'E')
            rightCows++;
    }

    sort(cows,cows+n,cmp);


    for(int i = 0; i < n; i++) {
        int curr = cows[i];
        if(direction[curr] == 'N') {
            sort(cows,cows+rightCows,cmpRight);
        } else {
            sort(cows+rightCows,cows+n,cmpUp);
        }
        int grassEaten = -1;
        for(int j = 0; j < n; j++) {
            int vs = cows[j];
            if(!stopped[vs] && direction[curr] != direction[vs] && location[vs].first + location[vs].second > location[curr].first + location[curr].second) {
                if(direction[curr] == 'N') {
                    if(location[vs].second > location[curr].second && location[vs].first < location[curr].first) {
                        grassEaten = location[vs].second - location[curr].second;
                    }
                } else {
                    if(location[curr].first < location[vs].first && location[curr].second > location[vs].second) {
                        grassEaten = location[vs].first - location[curr].first;
                    }
                }
                
            }
        }
        if(grassEaten != -1)
            stopped[curr] = true;
        ans[curr] = grassEaten;
    }

    for(int i = 0; i < n; i++) {
        if(ans[i] == -1) 
            cout << "Infinity" << "\n";
        else 
            cout << ans[i] << "\n";
    }
}