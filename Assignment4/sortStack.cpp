#include<bits/stdc++.h>
using namespace std;

void sortSubStack(stack<int>& s, int temp){
    if(s.empty()){
        s.push(temp);
    } else {
        int temp1 = s.top();
        if(temp1>temp){
            s.pop();
            sortSubStack(s, temp);
            s.push(temp1);
        } else {
            s.push(temp);
        }
    }
}

void sortStack(stack<int>& s){
    if(!s.empty()){
        int temp = s.top(); s.pop();
        sortStack(s);
        sortSubStack(s, temp);
    }
}



int main(){
    stack<int> s;
    s.push(50);
    s.push(19);
    s.push(7);
    s.push(90);
    s.push(-100);
    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}