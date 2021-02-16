#include<bits/stdc++.h>
using namespace std;

int possiblePaths(int m, int n){
    if(m==1||n==1) return 1;
    return possiblePaths(m-1, n) + possiblePaths(m, n-1);
}

int main(){
    cout<<possiblePaths(5, 5);
    return 0;
}