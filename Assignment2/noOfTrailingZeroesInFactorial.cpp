#include<bits/stdc++.h>
using namespace std;

int noOfZeroes(int num, int div){
    if(num/div==0) return 0;
    return (num/div) + noOfZeroes(num, div*5); 
}


int main(){
    int n = 1000;
    cout<<noOfZeroes(n, 5);
    return 0;
}