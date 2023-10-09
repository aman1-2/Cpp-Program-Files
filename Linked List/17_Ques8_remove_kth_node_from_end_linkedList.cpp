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

int getLength(Node* head){
    int length=0;

    while(head!=NULL){
        length++;
        head=head->next;
    }

    return length;
}

/*BRUTEFUL APPROACH:-
In which we have to traverse our linked list twice one for calculting the length of the linked list and other for finding
the node to be deleted from the end with the help of (length-k+1)
where,
length -> number of nodes in linked list.
k -> position which we have to remove. */
void removeKthNodeFromEnd(Node* head,int position){
    //Calculating the actual length of the linked list which will later on help us too find the position from ending to delete.
    int len=getLength(head);


    /* posi_end is to store the calculated position of the node from ending
    formula is (len-(position+1)+1) now here,
    len -> length of the linked list.
    position -> it is the position which we have to delete.(given by user)
    
    we do (position+1) so that the null position is not counted from the actual linked list. */
    int posi_end=(len-(position+1)+1),counter=1;

    /* While loop to point our pointer node one step ahead of the actual deleting node.
    So that we can change the linkage of its successor(before) node.*/
    while(counter<posi_end){
        head=head->next;
        counter++;
    } //After the while loop will terminate our pointer will be pointing one node ahead of its deleting node.
    
    /* we have just made a temp pointer which will be pointing to our node be deleted.which we will free once we have
    changed the linkage. */
    Node* temp=head->next;

    //Changing the linkage of the linked list.
    head->next=head->next->next;

    free(temp); //Freeing up or deleting the temp node form the memory space.

    return;
}

void optimizeRemoveKthNodeFromEnd(Node* &head,int positon){
    int len=getLength(head);
    if(positon>len){
        cout<<"The size of the node is less than the input ypu have provided so please update the value of position to be deleted"<<endl;
        return;
    }

    Node* ptr1=head;
    Node* ptr2=head;
    int counter=positon;

    while(counter--){
        ptr2=ptr2->next;
    }

    if(ptr2==NULL){
        Node* temp=head;
        head=head->next;
        free(temp);
        return; 
    }

    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    Node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);

    return;
}

int main(){
    linkedList ll;
    ll.insertAtTail(1);
    ll.insertAtTail(2);
    ll.insertAtTail(3);
    ll.insertAtTail(4);
    ll.insertAtTail(5);
    cout<<"Linked List:-"<<endl;
    ll.display();

    //removeKthNodeFromEnd(ll.head,4);
    optimizeRemoveKthNodeFromEnd(ll.head,5);
    cout<<"Linked List after deletion:-"<<endl;
    ll.display();

    return 0;
}