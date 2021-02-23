#include<bits/stdc++.h>
using namespace std;

bool dupParenthesis(string &str){
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];
            if(ch=='('){
                s.push(ch);
            }
            else if(ch==')'){
                if(s.empty()) return false;
                if(s.top()=='('){
                    s.pop();
                } else{
                    return false;
                }
            }
        }
    }
    if(s.empty()) return true;
    else return false;

}

int main(){
    string str = "((a+b))";
    if(dupParenthesis(str)){
        cout<<"Doesn't Contains Duplicate";
    } else {
        cout<<"Contains duplicate";
    }
    return 0;
}