#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
pair<int,int> points[41];
ll ans;
int x[41], y[41];

double isequal(double a, double b) { return abs(a-b) < 1e-6; }

int square(int x) { return x * x; }

double sidelen(int a, int b) {
  return sqrt(square(x[a]-x[b]) + square(y[a]-y[b]));
}

double heron(int a, int b, int c) {
  double sidea = sidelen(a,b);
  double sideb = sidelen(b,c);
  double sidec = sidelen(c,a);
  double semi = (sidea + sideb + sidec) / 2;
  sidea = semi - sidea;
  sideb = semi - sideb;
  sidec = semi - sidec;
  return sqrt(semi * sidea * sideb * sidec);
}
double inside(int a, int b, int c, int p) {
  return isequal(heron(a,b,p)+heron(b,c,p)+heron(c,a,p), heron(a,b,c));
}
double wedge(int a,int b,int c,int p) { // P is in the wedge that touches C, so expand triangle ABC into ABP
  return isequal(heron(a,c,p)+heron(b,c,p)+heron(a,b,c), heron(a,b,p));
}

double tArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

bool iT(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = tArea(x1,y1,x2,y2,x3,y3);
    double a1 = tArea(x,y,x2,y2,x3,y3);
    double a2 = tArea(x1,y1,x,y,x3,y3);
    double a3 = tArea(x1,y1,x2,y2,x,y);

    return (a==a1+a2+a3);
}
bool iW1(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = tArea(x1,y1,x2,y2,x3,y3);
    double a1 = tArea(x,y,x2,y2,x3,y3);
    double a2 = tArea(x1,y1,x,y,x3,y3);
    double a3 = tArea(x1,y1,x2,y2,x,y);

    return (a1==a+a2+a3);
}
bool iW2(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = tArea(x1,y1,x2,y2,x3,y3);
    double a1 = tArea(x,y,x2,y2,x3,y3);
    double a2 = tArea(x1,y1,x,y,x3,y3);
    double a3 = tArea(x1,y1,x2,y2,x,y);

    return (a2==a+a1+a3);
}
bool iW3(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = tArea(x1,y1,x2,y2,x3,y3);
    double a1 = tArea(x,y,x2,y2,x3,y3);
    double a2 = tArea(x1,y1,x,y,x3,y3);
    double a3 = tArea(x1,y1,x2,y2,x,y);

    return (a3==a+a1+a2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    string allNums;

    for(int i = 0; i < n; i++) {
        allNums += to_string(i);
    }

    for(int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
        x[i] = points[i].first;
        y[i] = points[i].second;
    }
    ans = 0;
    do {
        int a = (int)allNums[0]-'0';
        int b = (int)allNums[1]-'0';
        int c = (int)allNums[2]-'0';
        
        for(int i = 3; i < n; i++) {
            int p = (int)allNums[i]-'0';
            if(!inside(a, b, c,p)) {
                if(wedge(a, b, c,p)) {
                    c = p;
                }
                else if(wedge(b,c,a,p)) {
                    a = p;
                } 
                else if(wedge(a,c,b,p)) {
                    b = p;
                } 
                else {
                    ans--; 
                    break; 
                }
            }  
                
        }
        ans++;
        ans %= (int)(1e9+7);   
        
    }while(next_permutation(allNums.begin(), allNums.end()));
    cout << ans % (int)(1e9+7);
}