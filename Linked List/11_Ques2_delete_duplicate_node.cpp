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

    void insertAtHead(int value){
        Node* new_node=new Node(value);

        new_node->next=head;
        
        head=new_node;

        return;
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

void deleteDucplicateNode(Node* &head){
    Node* curr_position=head; //This Node is to make sure the current node position on which we are present.

    /*We have to delete the duplicate node till the time our current node not becomes NULL*/
    while(curr_position!=NULL){
        /*The second inner loop is too delete the duplicate node from the linked list.And the condition for
        iterating the loop is curr_position->value==curr_position->next->value and curr_position!=NULL.*/
       while(curr_position->value==curr_position->next->value && curr_position->next!=NULL){
        Node* temp=curr_position->next; //We have created temp so that we can point it too the duplicate node and delete it later on.

        curr_position->next=curr_position->next->next; //Now changing the node linkage.

        free(temp); //At the end we are just removing the duplicate node from the Linked List.
       }

       curr_position=curr_position->next; //At the last we have updated thevalue of our curr_position node.
    }

    return;
}

int main(){
    linkedList ll;
    ll.insertAtHead(1);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.display();

    deleteDucplicateNode(ll.head);

    ll.display();

    return 0;
}