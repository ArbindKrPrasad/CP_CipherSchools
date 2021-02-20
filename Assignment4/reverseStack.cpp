#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int temp){
    if(s.empty()){
        s.push(temp);
    } else {
        int t = s.top(); s.pop();
        insertAtBottom(s, temp);
        s.push(t);
    }
}

void reverseStack(stack<int> &s){
    if(!s.empty()){
        int temp = s.top(); s.pop();
        reverseStack(s);
        insertAtBottom(s, temp);
    }
    
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    reverseStack(s);
    cout<<s.top();
    return 0;
}