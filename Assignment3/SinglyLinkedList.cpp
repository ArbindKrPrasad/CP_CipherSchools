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
            prev = temp;
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
        Node* curr = head;
        while(curr!=NULL){
            cout<<curr->data;
        }
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
    // void deleteAtPosition(int pos){
    //     if(pos<0) return;
    //     if(head==NULL) return;
    //     if(pos==1){
    //         Node* temp = head;
    //         head = head->next;
    //         delete temp;
    //     }
    //     else if(pos==2){
    //         Node* temp = head->next;
    //         head->next = NULL;
    //         delete temp;
    //     } else{
    //         Node* curr = head;
    //         int count = 0;
    //         while(curr->next->next!=NULL && count<pos){
    //             curr = curr->next;
    //             count++;
    //         }
    //         if(curr->next->next!=NULL){
                
    //         }
            
    //     }
    // }

};



int main(){
    
    return 0;
}