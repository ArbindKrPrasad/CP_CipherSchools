#include<bits/stdc++.h>
using namespace std;

bool balance(string &str){
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch=='('||ch=='{'||ch=='['){
            s.push(ch);
        }
        else{
            if(s.empty()) return false;
            if(ch==')'){
                if(s.top()=='('){
                    s.pop();
                }
            }
            else if(ch=='}'){
                if(s.top()=='{'){
                    s.pop();
                }
            }
            else if(ch==']'){
                if(s.top()=='['){
                    s.pop();
                }
            }
        }
    }
    if(s.empty()) return true;
    else return false;

}

int main(){
    string str = "()";
    cout<<balance(str);
    return 0;
}