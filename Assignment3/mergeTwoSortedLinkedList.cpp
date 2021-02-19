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

SinglyLinkedList mergeTwoLinkedList(SinglyLinkedList* l1, SinglyLinkedList* l2){
    Node* curr1 = l1->head;
    Node* curr2 = l2->head;
    SinglyLinkedList res;
    
    res.head = new Node(0);
    Node* curr = res.head;
    
    while(curr1!=NULL&&curr2!=NULL){
        if(curr1->data<=curr2->data){
            curr->next = curr1;
            curr1 = curr1->next;
            curr = curr->next;
        } else{
            curr->next = curr2;
            curr2 = curr2->next;
            curr = curr->next;
        }
    }
    if(curr2!=NULL) curr->next = curr2;
    if(curr1!=NULL) curr->next = curr1;
    res.head = res.head->next;
    return res;
}



int main(){
    SinglyLinkedList l1 ;
    l1.insertAtEnd(5);
    l1.insertAtEnd(7);
    l1.insertAtEnd(10);
    l1.insertAtEnd(19);
    SinglyLinkedList l2;
    l2.insertAtEnd(3);
    l2.insertAtEnd(7);
    l2.insertAtEnd(14);

    SinglyLinkedList l  = mergeTwoLinkedList(&l1, &l2);
    l.printList();







    return 0;
}