#include<bits/stdc++.h>
using namespace std;

void sortZOT(vector<int>& vec){
    for(int i=0; i<vec.size(); i++){
        int first = 0, second = 0, third = vec.size()-1;
        while(second<third){
            switch(vec[second]){
                case 0:
                    if(vec[first]!=vec[second]){
                        swap(vec[first], vec[second]);
                    }
                    first++; second++;
                    break;
                case 1:
                    second++;
                    break;
                case 2:
                    if(vec[third]!=2){
                        swap(vec[second], vec[third]);
                    }
                    third--;
                    break;
                default:
                    break; 
            }
        }
    }
}

int main(){
    vector<int> vec = {0, 0, 2, 1, 0, 1, 2,2,2,0,0,0,1,2,1};
    sortZOT(vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}