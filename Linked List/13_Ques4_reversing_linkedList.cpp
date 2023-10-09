/* WAP where you have to reverse the linked list within it without using any other linked list. */
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

/* WAY-1 */
/* Reversing a Linked List with the help of Iterative approach. Here we have declared three variables to have track on
our linked list while reversing it.

One is previou pointer which will have the value NULL in it initiale because since we are reversing the linked list 
after reversing the first element will come out to be the lat element of the linked list which will then point to NULL.

The second element is the current Node which will tell on which node we are presently present. 

And at last we have next pointer which will hold the original linked list after reversing it .It's important because if
we just reverse the linkage of linked list then we will loose the original linked list data or linkage. */
Node* reverseLinkedList(Node* &head){

    Node* prev_ptr=NULL; //Previous Pointer intialize pointing to the value NULL.
    Node* curr_node=head; //Current Node is used to track the position of where we are currently present in the linked list.

    /* In the reversal process of linked list we basically follow these to steps:-
    (I) curr_node->next=prev_ptr
    (II)Moving ahead all the three elements(or variable) one step ahead. */
    while(curr_node!=NULL){
        Node* next_ptr=curr_node->next; //The next_ptr(next pointer) is used to point it to the current node's next value so that we shouldn't loose the information about our original linked list data.
        //Pointing the curr_nodes's next to previous pointer.
        curr_node->next=prev_ptr;

        //Moving ahead all the extra created variable(or element).
        prev_ptr=curr_node; //Updated the prev_pointer.
        curr_node=next_ptr; //Updated the curr_node.
        /*And since we have written the next_ptr line in the starting therefore the value of next_ptr automatically gets
        updated whenever we enter while loop in iteration the next_ptr automatically gets updated.*/
    }

    /* Since we have created this function with Node type of data type therfore we have to return a Node type value 
    and what we actually have to return is the new head of the linked list which will print our  linked list.
    We can either directly return the prev_ptr as when the while loop will terminate the prev_ptr will be at the head
    position of the reversed linked list.
    But for clearity we have returned the new_head.*/
    Node* new_head=prev_ptr;

    return new_head;
}

// WAY-2

Node* reverseReursion(Node* head){
    //Base case:-
    if(head==NULL || head->next==NULL)  return head;

    //Recursive case:-
    Node* new_head=reverseReursion(head->next); //Returning new_head from the function.

    //Self-work Case:-
    head->next->next=head;
    head->next=NULL;

    return new_head;

}

int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.display();
    cout<<endl;

    cout<<"Iterative approach:-"<<endl;
    ll.head = reverseLinkedList(ll.head);
    ll.display();
    cout<<endl;

    cout<<"Recursive approach:-"<<endl;
    ll.head = reverseReursion(ll.head);
    ll.display();

    return 0;
}