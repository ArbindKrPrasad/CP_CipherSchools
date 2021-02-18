#include<bits/stdc++.h>
using namespace std;

//----------------NOT WORKING--------------------//

bool isValid(vector<vector<int>> &mat, vector<vector<bool>>& visited , int r, int c, int n){
    if(r<0||c<0||r>=n||c>=n||mat[r][c]==0||visited[r][c]){
        return false;
    } else{
        return true;
    }
}

void ratInMaze(vector<vector<int>> &mat, vector<vector<bool>>& visited , int r, int c, int n, string path){  
    cout<<path<<endl; 
    visited[r][c] == true;

    if(r==n-1&&c==n-1){
        cout<<path<<endl;
        return;
    }
    
    if(isValid(mat, visited, r+1, c, n)){
        ratInMaze(mat, visited, r+1, c, n, path+"D");
    }else{
        return;
    }
    if(isValid(mat, visited, r-1, c, n)){
        ratInMaze(mat, visited, r-1, c, n, path+"U");
    }else return;
    if(!isValid(mat, visited, r, c-1, n)){
        ratInMaze(mat, visited, r, c-1, n, path+"L");
    } else return;
    if(isValid(mat, visited, r, c+1, n)){
        ratInMaze(mat, visited, r, c+1, n, path+"R");
    } else return;
    return;
}

int main(){
    vector<vector<int>> mat = {{1, 1, 1}, {1, 1, 1},{1, 1, 1}, {1, 1, 1}};
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    ratInMaze(mat, visited, 0, 0, 4, "");


    // for(vector<bool> x:visited){
    //     for(bool bo:x){
    //         cout<<bo<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}