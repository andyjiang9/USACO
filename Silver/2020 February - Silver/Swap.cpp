#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N, M, K;
int cows[100001];
bool visited[100001];

int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    fin >> N >> M >> K;

    for(int i = 1; i <= N; i++) {
        cows[i] = i;
    }
    
    for(int i = 0; i < M; i++) {
        int left;
        int right;
        fin >> left >> right;
        
        for(int j = 0; j < (right-left+1)/2; j++){
            int temp = cows[left + j];
            cows[left+j] = cows[right-j];
            cows[right-j] = temp;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            vector<int> cycles;
            cycles.push_back(i);       
            
            visited[i] = true;
            
            int next = cows[i];
            while(next != i) {
                cycles.push_back(next);
                visited[next] = true;
                int temp = cows[next];
                next = temp;
            }
            
            for(int j = 0; j < cycles.size(); j++) {
                cows[cycles[j]] = cycles[(j+K) % cycles.size()];
            }
        }

    }


    for(int i = 1; i <= N; i++) {
        fout << cows[i] << "\n";
    }   
}