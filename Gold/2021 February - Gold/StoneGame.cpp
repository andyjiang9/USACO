#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int nums[(int)1e5+1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] = nums[i] / 2 + 1;
    }
    sort(nums,nums+n);
    // find the largest number;
    int largestHalf = -1;
    for(int num:nums) {
        if(num > largestHalf)
            largestHalf = num;
    }

    ll total = 0;
    for(int num:nums) {
        if(num >= largestHalf)
            total += 
    }
    cout << total;
}
