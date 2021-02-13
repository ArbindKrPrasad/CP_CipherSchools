#include<bits/stdc++.h>
using namespace std;

void segeregate(vector<int>& vec){
    int start = 0, end = vec.size()-1;
    while(start<end){
        while(vec[start]==0&&start<end) start++;
        while(vec[end]==1&&start<end) end--;
        swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

int main(){
    vector<int> v = { 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0,0,0};
    segeregate(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}