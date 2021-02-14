#include<bits/stdc++.h>
using namespace std;

vector<int> largestSum(vector<int>& vec){
    int cs = vec[0];
    int os = vec[0];
    vector<int> cv = {vec[0]};
    vector<int> ov = {vec[0]};
    for(int i=0; i<vec.size(); i++){
        if(cs>=0){
            cs += vec[i];
            cv.push_back(vec[i]);
        } else {
            cs = vec[i];
            cv = {vec[i]};
        }
        if(cs>os){
            os = cs;
            ov = cv;
        }
    }
    return ov;
}

int main(){
    vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> res = largestSum(vec);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}