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

/* Function for Deleting a Node at the starting of the linked list. 
We pass in this one parameter that is Head of the Linked List. */
void deleteNodeAtHead(Node* &head){
    Node* temp=head; //This temp is made so that we can free the space of the hanging(i.e) to be deleted node.

    /* If we just move our head from the starting to the next then automatically the starting
    point of linked list will move. */
    head=head->next;

    free(temp); //Temp is storing the node which is needed to be free.
    /* Free is in-built feature in which we pass the pointer which we need to free the space
    from the memory. */

    return;

    /* Deleting a node from the starting of the head has a Time-Complexity of O(1).
    As we are not traversing the linked list instead we are deleting from the starting of the
    linked list. */
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

    deleteNodeAtHead(head);

    displayLinkedList(head);

    return 0;
}