#include<bits/stdc++.h>
using namespace std;

void buySellStock(const vector<int> & vec){
    int maxIndex = 0, minIndex = 0;
    for(int i=0; i<vec.size(); i++){
        if(vec[minIndex]>vec[i]) minIndex = i;
        if(vec[maxIndex]<vec[i]) maxIndex = i;
    }
    if(minIndex<maxIndex){
        cout<<minIndex<<" "<<maxIndex;
    } else {
        cout<<-1;
    }
}

int main(){
    vector<int> vec = {100, 180, 260, 310, 40, 535, 695};
    buySellStock(vec);
    return 0;
}