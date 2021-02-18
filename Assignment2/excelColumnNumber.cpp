#include<bits/stdc++.h>
using namespace std;

string alpha = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 

int columnNum(string str, int mul, int indx){
    if(indx<0) return 0;
    int pos = alpha.find(str[indx]);

    return (pos * mul) + columnNum(str, mul*26, indx-1);

}

int main(){
    string str = "  HCBBBCFKJEHFIUH";
    cout<<columnNum(str, 1, str.length()-1);
    return 0;
}