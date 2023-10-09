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
    Node* new_node=new Node(value);
    Node* temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new_node;

    return;
}

void deleteNodeAtHead(Node* &head){
    Node* temp=head;

    head=head->next;

    free(temp);

    return;
}

/* Function for Deleting a Node from a specific position of the linked list. 
We pass here two parameter that is Head of the Linked List and the position of the node which we
want to delete. */
void deleteNodeAtPosition(Node* &head,int position){
    /* If the position of the node which we want to delete is 0 then we can simple
    call the deleteNodeAtHead function and simple can return from the function. */
    if(position==0){
        deleteNodeAtHead(head);
        return;
    }

    //But let's say we want to delete a node at a specific position:-

    /* Create a temp which will hold the position node which we want to delete i.e the node
    which will be freed up later on in the program. */
    Node* temp;
    /* Now if we want to delete a node in that case we have to change the linkage of the node 
    one before the deleting node. */
    Node* before_position=head;
    int curr_position=0; //This is to maintain at which node we are currently. 

    /* While loop is to find out the node one before the deleting node. */
    while(curr_position!=position-1){
        before_position=before_position->next; 
        curr_position++;

        /* After the while loop will terminate we will be at the node before the deleting node
        which will be pointed by before_position. */
    }

    //temp is made to point to the node which we want to delete.
    temp=before_position->next;

    /* Here we are changing the linkage of before deleting node by pointing its next to after
    deleting node like this the node which we want to delete will be removed from the linked list. */
    before_position->next=before_position->next->next;

    /* And at last we just need to free up the deleting node. */
    free(temp);

    /*Time-complexity of deleting a specific node from the linked list is O(n)
    Where n is the one node before the deleting the node till there we have to traverse in any case.
    In this if we are provided with tail node then too nwe have to traverse our linked list
    as in singly linked list we cann't move back from the last node. */

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
    insertAtTail(head,5);
    displayLinkedList(head);

    deleteNodeAtPosition(head,2);
    deleteNodeAtPosition(head,0);

    displayLinkedList(head);

    return 0;
}