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
            while(curr->next!=NULL){
                curr= curr->next;
            }
            curr->next = temp;
        }
    }

    void insertAtPosition(int x, int pos){
        if(pos<0) return;
        Node* temp = new Node(x);
        if(head==NULL) head = temp;
        Node* curr = head;
        int count = 1;

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
            cout<<curr->data<<" ";
            curr = curr->next;
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

    void reverseLinkedListIterative(){
        if(head==NULL) return;
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* next = curr->next;
            curr->next= prev;
            prev = curr;
            curr = next;
            
        }
        head = prev;
        cout<<endl;
    }

    void reverseRecursiveFrom(Node* curr, Node* prev){
        if(curr==NULL) {
            head = prev;
            cout<<endl;
        }
        else{
            Node* next = curr->next;
            curr->next = prev;
            reverseRecursiveFrom(next, curr);
        }
        
    }

    void reverseLinkedListRecursive(){
        if(head==NULL) return;
        reverseRecursiveFrom(head, NULL);
    }



    // ---------------- PALENDROMIC LINKED LIST -----------------// 

    bool isPalendrome(){
        Node* fast = head;
        Node* slow = head;
        Node* firstHead = head;
        Node* slowprev, *fastprev;
        while(fast->next!=NULL&&fast->next->next){
            slowprev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        if(fast->next!=NULL){
            Node* slowNext = slow->next;
            slow->next=NULL;
            reverseRecursiveFrom(slowNext, NULL);
        } else{
            slowprev->next = NULL;
            reverseRecursiveFrom(slow, NULL);
        }
        
        Node* secondhead = head;

        while(firstHead!=NULL&&secondhead!=NULL){
            if(secondhead->data != firstHead->data){
                return false;
            }
            firstHead = firstHead->next;
            secondhead = secondhead->next;
        }
        return true;
    }
};



int main(){
    SinglyLinkedList l ;
    l.insertAtBegin(10);
    l.insertAtBegin(20);
    l.insertAtBegin(30);
    // l.insertAtBegin(20);
    l.insertAtBegin(20);
    l.insertAtBegin(10);
    l.printList();

    cout<<l.isPalendrome(); 

    return 0;
}