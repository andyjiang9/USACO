
#include <bits/stdc++.h>

using namespace std;

int n;
double arr[100000];
double prefix[100000];
double repeatmins[10001];

int main(){
    ifstream fin("homework.in");
    ofstream fout("homework.out");

    fin >> n;
    for(int i = 0; i < n; i++){
        fin >> arr[i];
    }
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + arr[i];
        repeatmins[(int)arr[i]]++;
    }

    double temp = 0;
    double maxAverage = -1;
    for(int k = 1; k < n-1; k++){
        while(repeatmins[(int)temp] == 0){
            temp++;
        }
        double average = (prefix[n-1] - prefix[k-1] - temp)/(n-k-1);
        maxAverage = max(maxAverage, average);
        repeatmins[(int)arr[k]]--;
    }

    vector<int> ans;
    temp = 0;
    int count = 0;
    for(int i = 1; i < n-1; i++)
        repeatmins[(int)arr[i]]++;

    for(int k = 1; k < n-1; k++){
        while(repeatmins[(int)temp] == 0){
            temp++;
        }
        double average = (prefix[n-1] - prefix[k-1]- temp)/(n-k-1);
        if(average == maxAverage){
            ans.push_back(k);
            count++;
        }
        repeatmins[(int)arr[k]]--;
    }

    for(int i = 0; i < ans.size(); i++){
        fout << ans.at(i) << endl;
    }
}
