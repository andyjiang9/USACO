#include <bits/stdc++.h>

using namespace std;

pair<int,int> square1[2];
pair<int,int> square2[2];
int minx, miny, maxx, maxy;

int main() {
    ifstream fin("square.in");
    ofstream fout("square.out");

    for(int i = 0; i < 2; i++) {
        int x, y;   
        fin >> x >> y;
        square1[i].first = x;
        square1[i].second = y;
    }

    for(int i = 0; i < 2; i++) {
        int x, y;   
        fin >> x >> y;
        square2[i].first = x;
        square2[i].second = y;
    }

    int minx = min(square1[0].first,square2[0].first);
    int miny = min(square1[0].second,square1[0].second);
    int maxx = max(square1[0].first,square2[0].first);
    int maxy = max(square1[0].second,square1[0].second);

    fout << (maxx - minx) * (maxy - miny);
}