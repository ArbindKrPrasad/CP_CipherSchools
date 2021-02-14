#include<bits/stdc++.h>
using namespace std;

void kSmallElement(vector<int>& vec, int k){
    sort(vec.begin(), vec.end());
    int i = k-1;
    for(i; i>=0; i--){
        cout<<vec[i]<<" ";
    }
}

int main(){
    vector<int> vec = {4, 2, 6, 8, 22, 6, 1, 0, 7};
    kSmallElement(vec, 4);
    return 0;
}