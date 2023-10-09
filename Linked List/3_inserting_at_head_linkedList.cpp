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

/* Function for inserting a Node at the beginning of the linked list. 
We pass in this two parameters One is Head of the Linked List and other is the value which we
have to insert in the new node. */
void insertAtHead(Node* &head,int value){
    /* Created a new_node where we will create our new node. 
    Once we have created our new_node then we have to insert it at the beginning of the linked list. */
    Node* new_node=new Node(value);

    /* As we are inserting the new_node at the starting of the linked list then we have to
    point the next Pointer of the new_node to the current head of the linked list. */
    new_node->next=head;

    /* Since we have added a new_node at the beginning of the linked list then we have to update
    the head pointer too now it should point to the new_node instead of the current head. */
    head=new_node;

    return;

    /* We have used head as the reference in our function because we need to upadte the value of
    head and make it point to the new_node. */

    /*Time-Complexity to insert a node at the starting of the Linked List is O(1).
    Whereas the Space-Complexity for this is too O(node) where node is the space or memory
    taken by the new inserted node. */
}

void displayLinkedList(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    return; 
}

int main(){
    /* We have created a head node and made it NULL. */
    Node* head=NULL;
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);

    displayLinkedList(head);

    return 0;
}