#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> vec){
    int vec_xor = vec[0];
    int sum_xor = 1;
    for(int i=2; i< vec.size()+1; i++){
        vec_xor^=vec[i-1];
        sum_xor^=i;
    }
    sum_xor^=vec.size()+1;
    
    return vec_xor^sum_xor;
}

int main(){
    vector<int> vec = {1, 2, 4, 5, 6};
    cout<<missingNumber(vec);
    return 0;
}