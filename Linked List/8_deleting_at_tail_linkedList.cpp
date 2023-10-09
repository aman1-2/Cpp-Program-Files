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

void insertAtHead(Node* &head,int value){
    Node* new_node=new Node(value);
    new_node->next=head;
    head=new_node;
    return;
}

void insertAtTail(Node* head,int value){
    Node* temp=head;
    Node* new_node=new Node(value);

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;

    return;
}

/* Function for Deleting a Node from the ending of the linked list. 
We pass in this one parameter that is Head of the Linked List. */
void deleteNodeAtTail(Node* head){

    Node* second_last=head; //This is for changing the linkage of the linked list.
    Node* temp; //This is to point to the delete node so that we can free up that space in memory.

    /* While our second_last node's next's next is NULL in that case we are at our second last node.
    and if not in that case we have to update it. */
    while(second_last->next->next!=NULL){
        //Change second_last to second_last->next.
        second_last=second_last->next;
    }

    /* Now this temp is used to store our last node which we want to delete which we will futher
    free up from the linked list so that it doesn't remain hanging in the memory. */
    temp=second_last->next;
    
    /* Whereas after pointing our temp to last node we just need to Point our second_last node
    to NULL. So that the linkage of the linked list is changed. */
    second_last->next=NULL;

    /*Free is in-built method which is used to free up the memory space of pointer temp. */
    free(temp);

    /*Time-complexity of deleting the last node from the linked list is O(n)
    Where n is the second last node.
    In this if we are provided with tail node then too nwe have to traverse our linked list
    till the second last node as in singly linked list we cann't move back from the last node
    to second last node. */

    return;
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
    Node* head=NULL;

    insertAtHead(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    displayLinkedList(head);

    deleteNodeAtTail(head);

    displayLinkedList(head);

    return 0;
}