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

/* Function for inserting a Node at the Ending or Tail of the linked list. 
We pass in this two parameters one is Head of the Linked List and other is the value which we
have to insert in the new node. */
void insertAtTail(Node* &head,int value){
    /* Created a new_node where we will create our new node. 
    Once we have created our new_node then we have to insert it at the ending of the linked list. */
    Node* new_node=new Node(value);

    /* Created a temp variable that is pointing to the head of the linked list to reach the 
    ending point of our linked list. */
    Node* temp=head;

    /* Here if our temp->next is not equal to NULL then keep on updating the temp to reach the
    ending node. */
    while(temp->next!=NULL){
        temp=temp->next;
        /* When we will move out of this our temp would be pointing to the end node. */
    }

    /* Then we have to point our temp-> next pointer to the new_node to attach the new_node in
    our linked list. */
    temp->next=new_node;

    /* Time Complexity for adding the node at the end of the linked list is O(n).
    Where n is the number of nodes in the linked list. 
    
    We can too acomplish the time-complexity as O(1) if provided with the tail node.In that case
    there won't be any need to traverse the linked list. */

    return;
}

void displayLinkedList(Node* head){
    //Created a temp variable to tarverse our linked list.
    Node* temp=head;

    //Terminating condition if the temp is not equall to next then print the temp->value.
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
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);

    displayLinkedList(head);

    return 0;
}