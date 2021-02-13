#include<bits/stdc++.h>
using namespace std;

bool majority(vector<int> vec){
    int majIndex = 0;
    int count = 0;
    for(int i = 1; i< vec.size(); i++){
        if(vec[majIndex]==vec[i]){
            count++;
        } else{
            count--;
        }
        if(count==0){
            majIndex = i;
            count++;
        }
    }

    int freq = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec[majIndex] ==vec[i]){
            freq++;
        }
    }
    if(freq>vec.size()/2) return true;
    else return false;
}

int main(){
    vector<int> vec = {1,1,3,2,4,4,4,4,4,4,1};
    cout<<majority(vec);
    return 0;
}