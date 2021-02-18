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
};

void removeLoop(Node* head){
    if(head == NULL) return;
    Node* fast = head;
    Node* slow = head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow==fast){
        slow = head;
        while(slow->next!=fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        cout<<fast->next->data;
        fast->next = NULL;
    }
}



int main(){
    SinglyLinkedList s;
    s.insertAtBegin(10);
    s.insertAtBegin(20);
    s.insertAtBegin(30);
    s.insertAtBegin(40);
    s.insertAtEnd(50);


    s.head->next->next->next->next->next = s.head->next->next;
    removeLoop(s.head);
    return 0;
}