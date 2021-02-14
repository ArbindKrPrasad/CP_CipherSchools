#include<bits/stdc++.h>
using namespace std;

int maxTrainPlatform(vector<int>& arri,vector<int>& dept){
    sort(dept.begin(), dept.end());
    sort(arri.begin(), arri.end());
    int currPlatform = 0, maxPlatform = 0;
    int arrIndex = 0, depIndex = 0;
    while(arrIndex<arri.size()&&depIndex<dept.size()){
        if(arri[arrIndex]<dept[depIndex]){
            currPlatform++;
            arrIndex++;
        } else if(arri[arrIndex]>dept[depIndex]){
            currPlatform--;
            depIndex++;
        }
        else{
            arrIndex++;
            depIndex++;
        }

        maxPlatform = max(maxPlatform, currPlatform);
    }
    return maxPlatform;
}

int main(){
    vector<int> arr = { 900, 940, 950, 1100, 1500, 1800 };
    vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    cout<<maxTrainPlatform(arr, dep);
    return 0;
}