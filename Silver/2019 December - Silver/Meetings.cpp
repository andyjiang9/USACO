#include <bits/stdc++.h>

using namespace std;

int n, l, t;
int location[(int)5e4+1];
int weight[(int)5e4+1];
int distances[(int)5e4+1];
vector<int> leftCows;
vector<int> rightCows;
long long currWeight, totalWeight;

bool sortingLeftInput(int a, int b) {return location[a] < location[b];}
bool sortingRightInput(int a, int b) {return location[a] > location[b];}

int main() {
    //ifstream fin("meetings.in");
    //ofstream fout("meetings.out");

    cin >> n >> l;
    // input stuffs
    for(int i = 0; i < n; i++) {
        int w, x ,d;
        cin >> w >> x >> d;

        if(d == 1) {
            rightCows.push_back(i);
        } else if(d == -1) {
            leftCows.push_back(i);
        } else {
            cout << "your bad\n";
        }
        
        location[i] = x;
        weight[i] = w;
        totalWeight += w;
    }
    totalWeight /= 2;
    // put them in order
    sort(rightCows.begin(),rightCows.end(),sortingRightInput);
    sort(leftCows.begin(),leftCows.end(),sortingLeftInput);
    // find the distances
    for(int i = 0; i < rightCows.size(); i++) {
        int currCow = rightCows.at(i);
        distances[currCow] = location[currCow];
    }
    for(int i = 0; i < leftCows.size(); i++) {
        int currCow = leftCows.at(i);
        distances[currCow] = l-location[currCow];
    }
    
    t = 0;
    currWeight = 0;
    
    while(currWeight < totalWeight) {

    }
    cout << t;
}