/* WAP where you are given two linked lists,Tellif they are equal or not.Two linked lists are equal if they have the 
same data and the arrangement of the data is too same. */
#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int value;
    Node* next;

    Node(int data){
        value=data;
        next=NULL;
    }
};

class linkedList{
public:
    Node* head;

    linkedList(){
        head=NULL;
    }

    void insertAtTail(int value){
        Node* new_node=new Node(value);

        if(head==NULL){
            head=new_node;
            return;
        }

        Node* temp=head;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;

        return;
    }

    void display(){
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->value<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;

        return;
    }
};

bool checkLinkedListsEqual(Node* head1, Node* head2){
    /* Important Thing too note it here is that we can too compare our value with head1 and head2 as our pointer
    instead of creating any new pointers as here we have passed our linked list head's with pass by value instead of
    pass by reference hence changes over here won't be reflected in our original linked list. */

    while(head1!=NULL && head2!=NULL){
        if(head1->value!=head2->value)  return false;

        head1=head1->next;
        head2=head2->next;

    }

    /* We will come out of the loop when or head1 becomes NULL or head2 becomes NULL or when both head1 and head2
    becomes NULL these are all the three possiblity when our while loop will terminate on its own.
    
    Now we have to return the value true only if the head1 and head2 after while loop termination are equal to NULL.
    Then only we say both the linked list are equal. */

    return (head1==NULL && head2==NULL);
}

int main(){
    linkedList ll1,ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);
    cout<<"Linked List 1:-"<<endl;
    ll1.display();

    ll2.insertAtTail(1);
    ll2.insertAtTail(2);
    ll2.insertAtTail(3);
    ll2.insertAtTail(5);
    ll2.insertAtTail(4);
    cout<<"Linked List 2:-"<<endl;
    ll2.display();

    bool result=checkLinkedListsEqual(ll1.head,ll2.head);
    if(result==true)    cout<<"Both the given linked lists are equal.";
    else    cout<<"Both the given linked lists are not equal.";

    return 0;
}