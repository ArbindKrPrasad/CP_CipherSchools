#include<bits/stdc++.h>
using namespace std;

// void printPermutation(string str, int cl,int l){
//     if(cl == l){
//         cout<<str<<endl;
//         return;
//     }
//     for(int i=cl; i<=l; i++){
//         swap(str[cl], str[i]);
//         printPermutation(str, cl+1, l);
//         swap(str[cl], str[i]);
//     }

// }

void printPermutation(vector<string> vec, int cl,int l){
    if(cl == l){
        for(int i=0; i<vec.size(); i++){
            if(i==vec.size()-1) cout<<vec[i];
            else cout<<vec[i]<<" > ";
        }
        cout<<endl;
        return;
    }
    for(int i=cl; i<=l; i++){
        swap(vec[cl], vec[i]);
        printPermutation(vec, cl+1, l);
        swap(vec[cl], vec[i]);
    }

}

int main(){
    vector<string> v = {"A2", "A3", "B2", "B1", "C1"};
    printPermutation(v, 0, 4);
    //printPermutation("ABC", 0, 2);
    return 0;
}