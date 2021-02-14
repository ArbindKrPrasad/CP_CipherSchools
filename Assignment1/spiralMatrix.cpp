#include<bits/stdc++.h>
using namespace std;

void printInSpiral(vector<vector<int>> mat){
    int rs = 0, re = mat.size()-1, cs = 0, ce = mat[0].size()-1;
    while(rs<=re&&cs<=ce){
        for(int i=cs; i<=ce; i++){
            cout<<mat[rs][i]<<" ";
        }
        rs++;
        for(int i=rs; i<=re; i++){
            cout<<mat[i][ce]<<" ";
        }
        ce--;

        if(re<=re){
            for(int i=ce; i>=cs; i--){
                cout<<mat[re][i]<<" ";
            }
            re--;
        }

        if(cs<=ce){
            for(int i=re; i>=rs; i--){
                cout<<mat[i][cs]<<" ";
            }
            cs++;
        }
    }
}

int main(){
    vector<vector<int>> mat = {{1, 4, 5, 6, 10}, {5, 2, 7, 9, 7},{8, 3, 6, 4, 8}, {2, 11, 4, 8, 6}};
    printInSpiral(mat);
    return 0;
}