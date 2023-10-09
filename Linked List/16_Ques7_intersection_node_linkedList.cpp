#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int value;
    Node* next;
    bool visited;

    Node(int data){
        value=data;
        next=NULL;
        visited=false;
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

/* Bruteful approach. 
Here we have tried to first visit every node of the first linked list and marked the visited value as true.
Then we tried to traverse the second linked list where we check that if at any node has the visited value to be
true then that node is only considered as the intersected node of the two linked list. 

The problem which we face here is that we have to traverse two times first for the first linked list and second time
for the second linked list. */
void findIntersectingNode(Node* head1,Node* head2){
    while(head1!=NULL){
        head1->visited=true;
        head1=head1->next;
    }

    while(head2!=NULL){
        if(head2->visited==true){
            cout<<"The point where too nodes meet is storing the value: "<<head2->value;
            return;
        }   else{
            head2->visited=true;
        }
        head2=head2->next;
    }

    cout<<"There is no intersecting point between the two given linked list.";
    return;
}

/* We are going to calculate the length of the linked list so that both the linked lists comes to one point from the
intersected node. */
int getLength(Node* head){
    int length=0;

    while(head!=NULL){
        length++;
        head=head->next;
    }

    return length;
}

Node* optimizedIntersectingNode(Node* head1,Node* head2){

    /* STEP:1 -> You can have two pointers to traverse the two linked list or you can too use head1 and head2 if passed
    the head as pass by value rather then pass by referene. */

    /* STEP:2 -> Calculate the length of the two linked lists. */
    int len1=getLength(head1);
    int len2=getLength(head2);
    int counter; //This is to store the difference between the length of the two linked lists.

    /* STEP:3 -> We have to move our bigger linked list's head(or ptr) with the steps equal to the counter value. */
    if(len1>len2){ //LL1 is bigger.
        counter=len1-len2;
        int i=1;
        while(i<=counter){
            head1=head1->next;
        }
    }   else { //LL2 is bigger.
        counter=len2-len1;
        int i=1;
        while(i<=counter){
            head2=head2->next;
        }
    }

    /* STEP:4 -> Comparing the two nodes of the linked list. */
    /* If we just pass the head in while condition then it will be false when the head becomes false. */
    while(head1){
        if(head1==head2){
            return head1;
        }

        head1=head1->next;
        head2=head2->next;

    }

    /* If there is no intersecting node then we just have to return the value NULL. */
    return NULL;

}

int main(){
    linkedList ll1,ll2;
    ll1.insertAtTail(1);
    ll1.insertAtTail(2);
    ll1.insertAtTail(3);
    ll1.insertAtTail(4);
    ll1.insertAtTail(5);

    ll2.insertAtTail(6);
    ll2.insertAtTail(7);
    // ll2.insertAtTail(8);
    // ll2.insertAtTail(9);
    // ll2.insertAtTail(10);
    ll2.head->next->next=ll1.head->next;

    findIntersectingNode(ll1.head,ll2.head);
    cout<<"\n\n\n";

    Node* intersected_node=optimizedIntersectingNode(ll1.head,ll2.head);

    if(intersected_node)    cout<<"The value which is stored inside the intersected node is: "<<intersected_node->value;
    else    cout<<"There is no intersected node present in the linked list.";

    return 0;
}