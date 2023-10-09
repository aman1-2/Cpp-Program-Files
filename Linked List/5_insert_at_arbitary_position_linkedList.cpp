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

/* Function for inserting a Node at a specific position in the linked list. 
We pass in this three parameters one is Head of the Linked List and other is the value which we
have to insert in the new node and third is the position where we have to insert that node. */
void insertAtPosition(Node* &head,int value,int position){
    /* If the position value is 0 that is if we have to add the node in the starting
    of the linked list then we can simply call our insertAt Head function to insert that node at
    the staring of the Linked List. */
    if(position==0){
        insertAtHead(head,value);
        return;
    }

    /* wheres if we have to insert it at some specific position in that scenario we first 
    have to create a new node and initialize it with the passed value. */
    Node* new_node=new Node(value);

    /* Then we have to create a temp which is used to traverse in our Linked List. */
    Node* temp=head;

    /* We have created a count variable that will check at which node we are currently present
    as we have to stop on node ahead of the position node provided.
    Because if we point the (position-1) node to our new node then we can simply place it at
    thw position in our linked list. */
    int count=0;

    /*While Loop to point our temp to the (position-1) node*/
    while(count!=position-1){
        temp=temp->next; //Moving the temp node 
        count++; //incrementing the count value.

        /* When we will terminate out of this Loop your temp will be on (positiion-1) node. */
    }

    /* Before pointing our temp to the new_node we firstly need to point our new_node to temp->next
    so as to maintain the connectivity.
    If we directly due temp->next=new_node; this then we can loose the information about rest of
    the nodes in linked list as the constructor has made new_node point to it NULL. */
    new_node->next=temp->next;
    temp->next=new_node;

    return;
}
/* Time Complexity for placinf a node at kth position in Average case is theta(position)
which means we have traverse our linked list till the position.
Whereas in the worst case it will be O(n) when we have to place the node at the ending of the
linked list in this case the n is the size of the linked list. */

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
    insertAtTail(head,5);
    insertAtPosition(head,4,3);

    displayLinkedList(head);

    return 0;
}