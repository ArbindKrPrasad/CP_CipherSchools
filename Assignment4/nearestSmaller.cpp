#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& vec){
    stack<int> s;
    int arr[vec.size()];
    vector<int> res;
    res.push_back(-1);
    s.push(vec[0]);
    for(int i=0; i>vec.size()-1; i++){
        int temp = s.top();
        while(temp>=vec[i]){
            
            s.pop();
            if(s.empty()){
                break;
            }
            temp = s.top();
        }
        if(s.empty()) res.push_back(-1);
        else res.push_back(temp);
        s.push(vec[i]);
    }
    vector<int> ret;
    for(int i=res.size()-1; i>=0; i--){
        ret.push_back(res[i]);
    }
    return ret;
}

int main(){
    vector<int> vec = {11, 13, 21, 3 };
    vector<int> res = nextGreater(vec);
    for(int i=0; i<vec.size(); i++){
        cout<< res[i]<<" ";
    }
    
    return 0;
}