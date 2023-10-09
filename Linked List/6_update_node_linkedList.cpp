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

/* Function for Updating a Node at a specific position in the linked list. 
We pass in this three parameters one is Head of the Linked List and other is the value which we
have to update in the node and third is the position where we have to update that node. */
void updateNode(Node* &head,int value,int position){
    /* If we have to Update the head node then we can directly go to the first position 
    (i.e) our head and update the value of head and simply return from there after updating the 
    head. */
    if(position==0){
        head->value=value;
        return;
    }

    /* Temp is used to traverse the head. */
    Node* temp=head;
    int curr_position=0; //curr_position variable is used to track the position of the current node.

    /* While loop is used to take our temp variable to the specified node where we have to update
    the value.
    Till the time the current_poition of node is not equal to the position.
    we need to move our temp. */
    while(curr_position!=position){
        temp=temp->next;
        curr_position++;

        /* After the while loop will terminate we will be at the specified node or position
        where we have to update the value of node. */
    }

    /* Since after while loop we are at correct position then we just need to update the value of
    temp. */
    temp->value=value;

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
    insertAtTail(head,4);

    updateNode(head,3,2);

    displayLinkedList(head);

    return 0;
}