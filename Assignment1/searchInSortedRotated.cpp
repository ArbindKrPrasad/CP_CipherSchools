#include<bits/stdc++.h>
using namespace std;

int searchIndex(vector<int>& vec, int k, int low, int high){
    if(low>high) return -1;
    
    int mid = low+(high-low)/2;
    if(vec[mid]==k) return mid;

    if(vec[low]<=vec[mid-1]){
        if(vec[low]<k&&vec[mid-1]>k){
            return searchIndex(vec, k, low, mid-1);
        }  else {
            return searchIndex(vec, k, mid+1, high);
        }
    }
    else{
        if(vec[mid+1]<k&&vec[high]>k){
            return searchIndex(vec, k, mid+1, high);
        } else{
            return searchIndex(vec, k, low, mid-1);
        }
    }
}

int main(){
    vector<int> vec = {4, 5, 6, 7,8, 1, 2, 3};
    cout<<searchIndex(vec, 2, 0, vec.size()-1);
    return 0;
}