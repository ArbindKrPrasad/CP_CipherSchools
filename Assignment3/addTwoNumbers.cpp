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
};

//--------ADD TWO NUMBERS-----------//

void addTwoNums(SinglyLinkedList* list1, SinglyLinkedList* list2){
    SinglyLinkedList res;
    list1->reverseLinkedListIterative();
    list2->reverseLinkedListIterative();
    // list1->printList();
    // cout<<endl;
    // list2->printList();
    // cout<<endl;
    Node* head1 = list1->head;
    Node* head2 = list2->head;
    // cout<<head1->data<<endl;
    // cout<<head2->data<<endl;

    int carry = 0;
    while(head1!=NULL||head2!=NULL){
        int sum = (head1==NULL?0:head1->data) +(head2==NULL?0:head2->data)+carry;
        res.insertAtBegin(sum%10);
        carry = sum/10;
        if(head1!=NULL){
            head1 = head1->next;
        }
        if(head2!=NULL){
            head2 = head2->next;
        }
        
        
    }
    if(carry!=0){
        res.insertAtBegin(carry);
    }
    
    Node* h = res.head;
    while(h!=NULL){
        cout<<h->data<<" ";
        h = h->next;
    }
}



int main(){
    SinglyLinkedList l1 ;
    l1.insertAtEnd(9);
    l1.insertAtEnd(9);
    l1.insertAtEnd(9);
    l1.insertAtEnd(9);

    SinglyLinkedList l2;
    l2.insertAtEnd(9);
    l2.insertAtEnd(9);
    l2.insertAtEnd(9);
    // l2.insertAtEnd(9);


    addTwoNums(&l1, &l2);
}