#include<bits/stdc++.h>
using namespace std;

/* Created a user define data type of node type that is used to create our linked list. */
class Node{
public:
    /* The value in the linked list can be of any type either string , boolean or even objects. */
    int value;
    /* The next pointer needs to point to the next address of our node hence next pointer should
    be of node data type. */
    Node* next;

    /*Creating a constructor*/
    Node(int data){
        value=data; //Storing the vlaue of data in our nodes value.
        next=NULL; //Give the next pointer value as NULL and later on we can point it too another node.
        /*Here we are always giving the next pointer the value NULL in the constructor assuming that
        its the last node of our linked list. */
    }
};

int main(){

    //Creating the nodes.
    Node* node1=new Node(1);
    Node* node2=new Node(2);
    node1->next=node2; //Storing the address node2 in the next ptr of node1.
    cout<<node1->value<<" "<<node1->next<<endl;
    cout<<node2->value<<" "<<node2->next<<endl;

    return 0;
}