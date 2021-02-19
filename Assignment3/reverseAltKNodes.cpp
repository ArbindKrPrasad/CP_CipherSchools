#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
    Node(){
        Node(0);
    }
};

class SinglyLinkedList{
    public:
    Node* head;
    SinglyLinkedList(){
        this->head = NULL;
    }

    void insertAtBegin(int x){
        Node* temp = new Node(x);
        if(head==NULL) head = temp;
        else{
            temp->next = head;
            head = temp; 
        }   
    }

    void insertAtEnd(int x){
        Node* temp = new Node(x);
        if(head == NULL) head = temp;
        else{
            Node* curr = head;
            Node* prev = NULL;
            while(curr!=NULL){
                prev = curr;
                curr= curr->next;
            }
            prev->next = temp;
        }
    }

    void insertAtPosition(int x, int pos){
        if(pos<0) return;
        Node* temp = new Node(x);
        if(head==NULL) head = temp;
        Node* curr = head;
        int count = 0;
        while(curr->next!=NULL && count<pos){
            curr = curr->next;
            count++;
        }
        if(curr->next==NULL){
            curr->next = temp;
        } else{
            temp->next = curr->next;
            curr->next = temp;
        }
    }

    void printList(){
        if(head==NULL) return;
        Node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

    void deleteAtBegin(){
        if(head==NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteAtEnd(){
        if(head==NULL) return;
        if(head->next==NULL){
            Node* temp = head;
            head = NULL;
            delete temp;
        } else{
            Node* curr = head;
            while(curr->next->next!=NULL){
                curr = curr->next;
            }
            Node* temp = curr->next;
            curr->next=NULL;
            delete temp;
        }
    }
    int getCount(){
        int count = 0;
        Node* curr = head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }
};


Node* reverseAltK(Node* head, int k, int alt){
    Node* curr = head, *next = NULL, *prev = NULL;
    int count = 0;
    
    if(alt%2==0){
        while(curr!=NULL&&count<k){
            cout<<curr->data<<" ";
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
    } else{
        while(curr!=NULL&&count<k){
            cout<<curr->data<<" ";
            curr = curr->next;
            count++;
        }
    }
    if(next!=NULL){
        Node* restHead = reverseAltK(next, k, alt+1);
        
        head->next = restHead;
    }

    return prev;
}


int main(){
    SinglyLinkedList l1;
    l1.insertAtEnd(5);
    l1.insertAtEnd(7);
    l1.insertAtEnd(10);
    l1.insertAtEnd(19);
    l1.insertAtEnd(20);
    l1.insertAtEnd(27);
    l1.insertAtEnd(15);
    l1.insertAtEnd(67);
    l1.insertAtEnd(23);
    l1.insertAtEnd(6);

    Node* nd = reverseAltK(l1.head, 3, 0);
    cout<<endl;
    while(nd!=NULL){
        cout<<nd->data<<" ";
        nd = nd->next;
    }
    return 0;
}