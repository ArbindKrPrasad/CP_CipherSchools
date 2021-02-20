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

class QueueL{
    public:
    Node* head;
    int size;
    QueueL(){
        this->head = NULL;
        this->size = 0;
    }

    void enqueue(int x){
        Node* temp = new Node(x);
        if(head==NULL){
            head = temp;
            size++;
        } 
        else{
            Node* curr  = head;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr->next = temp;
            size++;
        }
    }

    void dequeue(){
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

    int getFront(){
        if(head==NULL) return -1;
        if(head->next==NULL) return head->data;
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        return curr->data;
    }

    int getBack(){
        if(head==NULL) return -1;
        else{
            return head->data;
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
    QueueL s;
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