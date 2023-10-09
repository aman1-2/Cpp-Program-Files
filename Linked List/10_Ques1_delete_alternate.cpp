/* WAP where you are given the head of the linked list,delete every alternate node form the
list starting from the second node?? */

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

/* Function for Deleting alternate nodes from the linked list. 
We pass here one parameter that is Head of the Linked List. */
void deleteAlternateNode(Node* &head){
    /* We have created a current_node that is use to traverse our linked list starting from the
    head of the linked list. */
    Node* current_node=head;

    /* We have to delete the alternate nodes from the linked list for this we have to run the same
    steps until our current_node has reached NULL or our current_node->next has started pointing 
    to NULL. */
    while(current_node!=NULL && current_node->next!=NULL){
        /* Since we have to delete the alternate node's hence created a temp to point to the 
        alternate node which we have to delete as we have to free it up too at the end. */
        Node* temp=current_node->next;

        /* Now before deleting the alternate we need to make a linkage between other two nodes
        of our linked list which is done as mentioned below. */
        current_node->next=current_node->next->next;

        /* At the end we just need to free up the space of the deleted node from our memory space. */
        free(temp);

        //And then just upadate the current_node.So as to repeat the same steps untill the 
        //current_node reaches Null or it start's pointing to the NULL.
        current_node=current_node->next;
    }

    return;
}

int main(){
    cout<<"For Odd Case:-"<<endl;
    linkedList ll;
    for(int i=1;i<=5;i++){
        ll.insertAtTail(i);
    }
    ll.display();

    deleteAlternateNode(ll.head);

    ll.display();

    cout<<"For Even Case:-"<<endl;
    linkedList ll1;
    for(int i=1;i<=6;i++){
        ll1.insertAtTail(i);
    }
    ll1.display();

    deleteAlternateNode(ll1.head);

    ll1.display();

    return 0;
}