#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int r, int c){
    if(r==1||c==1) return 1;
    return uniquePaths(r-1,c)+uniquePaths(r, c-1);
}

int main(){
    cout<<uniquePaths(3, 7);
    return 0;
}