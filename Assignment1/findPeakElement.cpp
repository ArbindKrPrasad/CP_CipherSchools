#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> vec){
    if(vec.size()==0) return -1;
    if(vec.size()==1) return vec[0];
    int peakValue = vec[0];
    for(int i= 1 ;i<vec.size(); i++){
        if(peakValue<vec[i]) peakValue = vec[i];
    }
    return peakValue;
}

int main(){
    vector<int> vec = {200,1,3,2,4,4,4,4,4,4,100};
    cout<<peakElement(vec);
    return 0;
}