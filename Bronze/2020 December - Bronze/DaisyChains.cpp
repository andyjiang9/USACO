#include <bits/stdc++.h>

using namespace std;
int n;
int flowers[101];
int total;
double average;
int ans;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> flowers[i];
    }
    ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            total = 0;
            int tflowers = 0;
            for(int k = i; k <= j; k++) {
                total += flowers[k];
                tflowers++;
            }

            average = (double)total/tflowers;
            for(int k = i; k <= j; k++) {
                if(average == flowers[k]) {
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
}