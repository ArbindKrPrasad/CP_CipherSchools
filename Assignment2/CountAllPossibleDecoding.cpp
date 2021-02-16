#include<bits/stdc++.h>
using namespace std;

string alp = "_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void decode(string str, int indx, string res){
    if(indx>=str.size()){
        cout<<res<<endl;
        return;
    }
    int fd = int(str[indx]-'0');
    if(fd==0){
        return;
    }
    decode(str, indx+1, res+alp[fd]);

    if(indx+1>=str.size()){
        return;
    }

    int ftd = int(str[indx+1]-'0');
    if(10*fd+ftd<=26){
        
        decode(str, indx+2, res+alp[10*fd+ftd]);
    }
    
}

int main(){
    decode("123456253", 0, "");
    return 0;
}