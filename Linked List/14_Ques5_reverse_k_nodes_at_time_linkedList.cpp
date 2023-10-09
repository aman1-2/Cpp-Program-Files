/* WAP where you are given head of a linked list, reverse the nodes of the linked list k at a time and return the
modified linked list. */
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

Node* reverseTillKAtTimes(int times, Node* &head){
    //Self-work:-
    Node* prev_ptr=NULL;
    Node* curr_node=head;

    int counter=1; //This is for counting the first k nodes.

    //Reversing k nodes at a time.
    while(curr_node!=NULL && counter<=times){
       Node* next_ptr=curr_node->next;
       curr_node->next=prev_ptr;

       //Moving ahead all my three Node pointers.
       prev_ptr=curr_node;
       curr_node=next_ptr;

       //Everything was same till here as we reverse our linked list with recursive approach.
       //Extar additivive thing in this is that we have to increment our counter value.
       counter++;
    }

    //After we will come out of this while loop your prev_ptr will be pointing as the new_head of our linked list.

    /*Recursive call:-
    So from the above while loop our curr_node will be pointing to the new_head of the recursive call. */
    if(curr_node!=NULL){
        Node* new_head=reverseTillKAtTimes(times,curr_node);

        //Now we have to just link our just reversed nodes and the recieved recursive nodes.
        head->next=new_head;
    } 

    return prev_ptr; //prev_ptr will give the new_head of the connected linked list.
}

int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    ll.insertAtTail(6);
    ll.display();

    ll.head=reverseTillKAtTimes(4,ll.head);

    ll.display();

    return 0;
}