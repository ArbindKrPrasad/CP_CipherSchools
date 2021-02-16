#include<bits/stdc++.h>
using namespace std;

void printPermutation(string str, int cl,int l){
    if(cl == l){
        cout<<str<<endl;
        return;
    }
    for(int i=cl; i<=l; i++){
        swap(str[cl], str[i]);
        printPermutation(str, cl+1, l);
        swap(str[cl], str[i]);
    }

}

int main(){
    printPermutation("ABC", 0, 2);
    return 0;
}