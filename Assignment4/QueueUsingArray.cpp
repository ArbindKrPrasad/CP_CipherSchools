#include<bits/stdc++.h>
using namespace std;

class QueueArray{
    
    public:
    int *arr;
    int top;
    int cap;
    QueueArray(int size){
        arr = new int[cap];
        this->cap = size;
        this->top = -1;
    }
    QueueArray(){
        QueueArray(10);
    }

    void enqueue(int x){
        if(cap<=top-1){
            cout<<"overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void dequeue(){
        if(top==-1){
            cout<<"underflow"<<endl;
            return;
        }
        else{
            for(int i=0; i<top; i++){
                arr[i] = arr[i+1];
            }
            top--;
        }
        
    }
    int getFront(){
        return arr[top];
    }
    int getBack(){
        return arr[0];
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
    QueueArray s(10);
    s.enqueue(10);
    s.enqueue(20);
    s.print();
    s.enqueue(30);
    cout<<endl<<s.getFront()<<" "<<s.getBack()<<endl;
    s.print();
    s.dequeue();
    s.dequeue();
    cout<<s.isEmpty()<<endl;
    s.dequeue();
    cout<<s.isEmpty()<<endl;

}