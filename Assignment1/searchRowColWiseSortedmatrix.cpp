#include<bits/stdc++.h>
using namespace std;

bool searchInMat(vector<vector<int>> vec, int k){
    int r = vec.size()-1, c = vec[0].size()-1;
    int cr = 0, cc = c;
    while(cr<=r&& cc>=0){
        if(vec[cr][cc]==k) {
            cout<<cr<<" "<<cc;
            return true;
        } else if(vec[cr][cc]<k){
            cr++;
        } else{
            cc--;
        }
        
    }
    return false;
}

int main(){
    vector<vector<int>> mat = { {10, 20, 30, 40},
                                {15, 25, 35, 45},
                                {27, 29, 37, 48},
                                {32, 33, 39, 50}};
    
    searchInMat(mat, 32);
    return 0;
}