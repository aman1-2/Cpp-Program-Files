#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    //Nodes two parts:- (i)Data (ii)Next
    int value;
    Node* next;

    //Creating a constructor for the node.
    Node(int data){
        value=data;
        next=NULL;
    }
};

/*A travesal Function that will Traverse our passed Linked List form the Head Node. */
void travesal(Node* head){
    /* Created a temp variable which will help in traversing and it is Pointing to head node in
    starting. */
    Node* temp=head;

    /* And this temp will go on traversing the linked list untill our temp variable is equall to
    the NULL-> It's the stopping condition for our traversal. */
    while(temp!=NULL){
        /* Before Updating the value of the temp we just need to print the value present in our
        current node. */
        cout<<temp->value<<"->";
        /* And then we need to move the temp node with one step ahead by pointing the temp to
        the temp->next. */
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

    /* Here we have taken an extra variable to traverse our linked list instead of using head Node.
    The reason why we don't use the head node is once we update the value of head node then we
    will loose the data that from where our linked list was starting. */

    return;
}

int main(){
    Node* head=new Node(1);
    Node* node2=new Node(2);
    Node* node3=new Node(3);
    Node* node4=new Node(4);

    //Placing the next pointer of each node at its correct position to make it a linked list.
    head->next=node2;
    node2->next=node3;
    node3->next=node4;

    //Now calling the traversal function to traverse through our linked list and print all the values.
    travesal(head);
    
    return 0;
}