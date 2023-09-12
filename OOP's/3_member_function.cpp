/*We can directly access the member function as we normally access the data members of the
objects with the help of (.) dot operator....

There are two ways in which we can declare the the member function as:-
(a)Inline class function   (b)Outside function....*/

#include<bits/stdc++.h>
using namespace std;
class student{
public:
    string name;

    //Inline function....
    void print(){
        cout<<"Hello your name is Aman."<<endl;
        return;
    }

    //Outside class function
    void out(); /*To define a function outside the class we firstly need to mention that 
    this function actually is a member function of this class.Although defining it 
    outside this function then too we need to declare it inside this class.....*/
};
//Defining the function outside the class..
void student:: out(){
    cout<<"Function is defined outside the class but it is declared inside the class which indicates its the part of the class as its member function."<<endl;
    return;
}
int main(){
    student aman; //Created the object for student class...
    aman.print(); //Calling the inline function of the class student...
    aman.out();  //Calling the outside defined function...

    //We can too pass n number of parameters to our function...
    return 0;
}