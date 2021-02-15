#include<bits/stdc++.h>
using namespace std;

void parenthesis(string str, int op, int cl, int n){
    if(cl>=n){
        cout<<str<<endl;
        return;
    }
    if(op>cl){
        str+=")";
        parenthesis(str, op, cl+1, n);
        str = str.substr(0, str.length()-1);
    }
    if(op<n){
        str+="(";
        parenthesis(str, op+1, cl, n);
    }
}

int main(){
    int numOfParen = 5;
    parenthesis("", 0, 0, numOfParen);
    return 0;
}