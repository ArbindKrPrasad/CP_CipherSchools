#include<bits/stdc++.h>
using namespace std;

string alpha = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

string columnTitle(int num){
    if(num==0) return "";
    if(num==26) return "Z";
    return columnTitle(num/26)+alpha[num%26];
}

int main(){
    int n = 16384;
    cout<<columnTitle(n);
    return 0;
}