#include<bits/stdc++.h>
using namespace std;

class StackArray{
    int *arr;
    int top;
    int cap;
    public:
    StackArray(int size){
        arr = new int[cap];
        this->cap = size;
        this->top = -1;
    }
    StackArray(){
        StackArray(10);
    }

    void push(int x){
        if(cap<=top-1){
            cout<<"overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top==-1){
            cout<<"underflow"<<endl;
            return;
        }
        top--;
    }

    bool isEmpty(){
        return top==-1;
    }

    int size(){
        return top+1;
    }

    void print(){
        if(top==-1) cout<<"Stack is Empty"<<endl;
        for(int i=0; i<=top; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    StackArray s(10);
    s.push(10);
    s.push(20);
    s.print();
    s.push(30);
    s.print();
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<s.isEmpty()<<endl;

}