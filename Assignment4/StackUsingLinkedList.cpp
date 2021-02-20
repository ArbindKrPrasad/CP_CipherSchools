#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class StackL{
    public:
    Node* head;
    int size;
    StackL(){
        this->head = NULL;
        this->size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        if(head==NULL){
            head = temp;
            size++;
        } 
        else{
            temp->next = head;
            head = temp;
            size++;
        }
    }

    void pop(){
        if(head==NULL) cout<<"UnderFlow"<<endl;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    bool isEmpty(){
        return head==NULL;
    }

    int length(){
        return size;
    }

    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }


};

int main(){
    StackL s;
    cout<<s.length()<<endl;
    s.push(10);
    s.push(20);
    cout<<s.length()<<endl;
    s.print();
    s.pop();
    s.print();
    cout<<s.isEmpty()<<endl;
    s.pop();
    cout<<s.isEmpty()<<endl;
}