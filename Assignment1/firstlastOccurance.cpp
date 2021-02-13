#include<bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int>& vec, int start, int end, int k){
    int mid = start+(start-end)/2;
    if((mid==0||k>vec[mid-1])&&vec[mid]==k) return mid;
    else if(vec[mid]>k) return firstOccurance(vec, start, mid-1, k);
    else return firstOccurance(vec, mid+1, end ,k);
}

int lastOccurance(vector<int> vec, int start, int end, int size, int k){
    int mid = start+(end-start)/2;
    if((mid==size-1||k<vec[mid+1])&&vec[mid]==k){
        return mid;
    }
    else if(vec[mid]>k) return lastOccurance(vec, start, mid-1, size, k);
    else return lastOccurance(vec, mid+1, end, size, k);
}

int main(){
    vector<int> vec = {1,1,2,3,4,4,4,4,4,4,8};
    cout<<firstOccurance(vec, 0, vec.size()-1, 4)<<" "<<lastOccurance(vec, 0, vec.size()-1, vec.size(), 4)<<endl;
    return 0;
}