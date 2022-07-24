#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n, k;
int board[100][10];
int groups[100][10];
int groupSizes[1001];

void gravity() {
    for(int j = 0; j < 10; j++) {
        for(int i = n-1; i >= 0; i--) {
            if(board[i][j] == 0) {
                int max0 = i;

                while(max0 >= 0 && board[max0][j] == 0)
                    max0--;

                if(max0 == -1)
                    break;
                
                board[i][j] = board[max0][j];
                board[max0][j] = 0;
            }
        }
    }
}

void dfs(int row, int column, int number, int groupNumber) {
    if(row < 0 || row >= n || column < 0 || column >= 10 || board[row][column] != number || groups[row][column] != 0) return;
    
    groups[row][column] = groupNumber;
    groupSizes[groupNumber]++;
    
    dfs(row+1,column,number,groupNumber);
    dfs(row-1,column,number,groupNumber);
    dfs(row,column+1,number,groupNumber);
    dfs(row,column-1,number,groupNumber);
}

bool solve() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 10; j++)
            groups[i][j] = 0;
    
    for(int i = 0; i < n*10+1; i++) 
        groupSizes[i] = 0;

    int currGroupNumber = 1;        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            if(board[i][j] != 0 && groups[i][j] == 0)
                dfs(i,j,board[i][j],currGroupNumber++);       
        }
    }

    bool progress = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            if(groupSizes[groups[i][j]] >= k && board[i][j] != 0) {
                board[i][j] = 0;
                progress = true;
            }
                 
        }
    }

    gravity();

    return progress;
}

int main() {
    ifstream fin("mooyomooyo.in");
    ofstream fout("mooyomooyo.out");

    fin >> n;
    fin >> k;
    string hi;
    getline(fin,hi);

    for(int i = 0; i < n; i++) {
        string input;
        getline(fin,input);
        
        for(int j = 0; j < input.length(); j++)
            board[i][j] = input.at(j) - '0';
    }
    
    while(solve());
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 10; j++) {
            fout << board[i][j];
        }
        fout << endl;
    }
}