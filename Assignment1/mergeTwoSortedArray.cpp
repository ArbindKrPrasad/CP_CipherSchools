#include<bits/stdc++.h>
using namespace std;

vector<int> merge(const vector<int>& v1,const vector<int>& v2){
    vector<int> res;
    int i=0, j=0;
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]<=v2[j]){
            res.push_back(v1[i]);
            i++;
        }
        else{
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        res.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        res.push_back(v2[j]);
        j++;
    }
    return res;
}

int main(){
    vector<int> vec1 = { 1, 3, 4, 5};
    vector<int> vec2 = {2, 4, 6, 8};
    vector<int> vec = merge(vec1, vec2);
    for(int item:vec){
        cout<<item<<" ";
    }

    return 0;
}