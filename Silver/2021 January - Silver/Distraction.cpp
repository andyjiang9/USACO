#include<iostream>
using namespace std;
int b[10], a[10];
int main() {
 for(int i=0; i<10; i++)
  a[i]=i;
 for(int i=0; i<11; i++) // oops typo
  b[i] = i;
 for(int i=0; i<10; i++)
  cout << a[i] << ' ';
 cout << '\n';
 for(int i=0; i<10; i++)
  cout << b[i];
}