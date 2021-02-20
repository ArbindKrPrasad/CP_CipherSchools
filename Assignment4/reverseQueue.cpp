#include<bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q){
    if(!q.empty()){
        int temp = q.front(); q.pop();
        reverseQueue(q);
        q.push(temp);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.front();
}