#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n;
pair<int,int> points[100000];
int pointID[100000];
long long sumX[100000];
long long sumY[100000];

bool compareX(int a, int b) {
    if(points[a].first == points[b].first)
        return points[a].second < points[b].second;
    return points[a].first < points[b].first;
}

bool compareY(int a, int b) {
    if(points[a].second == points[b].second)
        return points[a].first < points[b].first;
    return points[a].second < points[b].second;
}

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    fin >> n;

    for(int i  = 0; i < n; i++) {
        fin >> points[i].first;
        fin >> points[i].second;
        pointID[i] = i;
    }
    
    sort(pointID,pointID+n,compareX);
    for(int i = 0; i < n; i++) {
        int topPoint = i+1;
        int numLine = 0;
        while(points[pointID[i]].first == points[pointID[topPoint]].first) {
            sumY[pointID[i]] += points[pointID[topPoint]].second - points[pointID[i]].second;
            topPoint++;
            numLine++;
        }
        long long previous = sumY[pointID[i]];
        topPoint = i+1;
        while(points[pointID[i]].first == points[pointID[topPoint]].first) {
            
            sumY[pointID[topPoint]] = previous + (points[pointID[topPoint]].second - points[pointID[topPoint-1]].second) * (topPoint-i-numLine + topPoint-i-1);
            
            previous = sumY[pointID[topPoint]];
            topPoint++;
        }
        
        i = topPoint-1;
    }

    sort(pointID,pointID+n,compareY);
    for(int i = 0; i < n; i++) {
        int topPoint = i+1;
        int numLine = 0;
        while(points[pointID[i]].second == points[pointID[topPoint]].second) {
            sumX[pointID[i]] += points[pointID[topPoint]].first - points[pointID[i]].first;
            topPoint++;
            numLine++;
        }
        long long previous = sumX[pointID[i]];
        topPoint = i+1;
        while(points[pointID[i]].second == points[pointID[topPoint]].second) {
            
            sumX[pointID[topPoint]] = previous + (points[pointID[topPoint]].first - points[pointID[topPoint-1]].first) * (topPoint-i-numLine + topPoint-i-1);
    
            previous = sumX[pointID[topPoint]];
            topPoint++;
        }

        i = topPoint-1;    
    }

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += sumX[i] * sumY[i] % 1000000007;
        sum %= 1000000007;
    }
    fout << sum;
}