#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class dequeueArray{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    void pushBack(int x){
        Node* temp = new Node(x);
        if(head==NULL){
            head = temp;
            tail = temp;
        } else {
            temp->prev = tail;
            tail->next = temp;
            tail = tail->next;
        }
        
    }

    void pushFront(int x){
        Node* temp = new Node(x);
        if(head==NULL){
            head = temp;
            tail = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        
    }
    
    void popFront(){
        if(head==NULL) return;
        if(head->next==NULL){
            Node* temp = head;
            head=NULL;
            delete temp;
        } else {
            Node* temp = head;
            head->next->prev = NULL;
            head = head->next;
            delete temp;
        }
    }

    void popBack(){
        if(head==NULL) return;
        if(head->next==NULL){
            Node* temp = head;
            head = NULL;
            delete temp;
        } else{
            Node* temp = tail;
            tail->prev->next = NULL;
            delete temp;
        }
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
    dequeueArray da;
    da.pushFront(10);
    da.pushFront(20);
    da.pushBack(30);
    da.pushBack(40);
    da.popBack();
    da.popFront();
    da.print();
    return 0;
}