#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> nextGreater(vector<int>& vec){
    stack<int> s;
    int arr[vec.size()];
    vector<int> res;
    res.push_back(-1);
    s.push(vec[vec.size()-1]);
    for(int i=vec.size()-2; i>=0; i--){
        int temp = s.top();
        while(temp<=vec[i]){
            
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
    vector<vector<int>> ret;
    for(int i=res.size()-1; i>=0; i--){
        ret[0].push_back(res[i]);
        ret[1].push_back(i);
    }
    return ret;
}

vector<int> slidingWindowMax(vector<int> vec, int k){
    vector<vector<int>> nge = nextGreater(vec);
    vector<int> res;
    for(int i=0; i<nge[0].size()-k+1; i++){
        int start = 0, end = k-1;
        int j = start;

        while(j<=end){
            if(nge[1][j]<=end){
                j = nge[1][j];
            } else {
                res.push_back(vec[j]);
                start++;
                end++;
            }
        }
    } 
    return res;
}

int main(){
    vector<int> vec = {1, 2, 3, 1, 4, 5, 2, 3, 6 };
    vector<int> res = slidingWindowMax(vec, 3);
    for(int i=0; i<vec.size(); i++){
        cout<< res[i]<<" ";
    }
    
    return 0;
}