#include<bits/stdc++.h>
using namespace std;

bool doesMeet(int p1, int v1, int p2, int v2){
    if(p1>p2&&v1>v2) return false;
    if(p2>p1&&v2>v1) return false;
    if(v1<v2){
        swap(v1, v2);
        swap(p1, p2);
    }

    return ((p1 - p2)% (v1-v2)==0);
    
}

int main(){
    
    int p1 = 5;
    int v1 = 8;
    int p2 = 4;
    int v2 = 2;
    bool res = doesMeet(p1, v1, p2, v2);
    if(res) cout<<"Yes";
    else cout<<"No";
    return 0;

}