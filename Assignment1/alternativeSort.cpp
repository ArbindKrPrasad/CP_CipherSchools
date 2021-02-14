#include<bits/stdc++.h>
using namespace std;

void altSort(vector<int> vec){
    sort(vec.begin(), vec.end());
    int f = 0, l = vec.size()-1;
    while(f<l){
        cout<<vec[l]<<" "<<vec[f]<<" ";
        f++;
        l--;
    }

    if(vec.size()%2!=0) cout<<vec[f]<<" ";
}

int main(){
    vector<int> vec = {4, 2, 6, 8, 22, 6, 1, 0, 7};
    altSort(vec);
    return 0;
}