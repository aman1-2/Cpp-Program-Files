/* WAP Where you are given a singly Linked List and you have to print that linked list in reverse order. Without actually
reversing the linked list. */
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

/*To Print our linked list in reverse order we have used recursive approach as in reccursion stack the element which
goes first inside the stack comes out at last as it follows LIFO concept and here too somewhat same concept we have to 
use where we have to print 1 at the end and 5 at the beginning. */
void printReversedLinkedList(Node* head){
    /* Tried to have a recursive system here.
    Where we give a base condition first and in our case the base condition is that it has to stop when we recah the
    NULL that is on the very last node. */
    if(head==NULL)  return;

    /* Assumption -> That it will give the printed reverse linked list till head we just have to print the value of
    head. In assumption we just have to call this function with head->next.  */
    printReversedLinkedList(head->next);

    /* At the last the self work is that we have too just print the value of the current head nodes's value. */
    cout<<head->value<<" ";
}

int main(){
    linkedList ll;
    ll.insertAtHead(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);

    ll.display();

    printReversedLinkedList(ll.head);

    return 0;
}