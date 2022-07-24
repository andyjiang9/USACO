#include <bits/stdc++.h>

using namespace std;

int n;
int nums[1001];
int oddNumbers, evenNumbers;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        if(nums[i] % 2 == 1) {
            oddNumbers++;
        } else {
            evenNumbers++;
        }
    }

    if(abs(oddNumbers - evenNumbers) > 3) {
        int randomNumber = (oddNumbers-evenNumbers)/2 - 1;
        oddNumbers -= 2 * randomNumber;
        evenNumbers += randomNumber;
    }

    while(oddNumbers - evenNumbers > 1) {
        oddNumbers -= 2;
        evenNumbers += 1;
    }

    while(oddNumbers > evenNumbers) {
        oddNumbers -= 2;
    }


    cout << oddNumbers + evenNumbers;
}   