#include<bits/stdc++.h>
using namespace std;

class student{ 
public: //Access specifier.

    string name; //Data member (Attribute)
    int roll_no; //Data member (Attribute)

    void welcome(){ //Member Function (Method)
        cout<<"Hello World!!";
    }

};
int main(){
    //Creating an Object -> An object is a variable of type class.

    //Class_name object_name;
    student s1;

    /*So student is a class and s1 is its object

    For accessing the memebr of classes we use a dot (".") operattor

    Initializing the values of the objects member.*/

    s1.name="Aman"; /*The dot operator is used as follow we firstly give the
    object_name.data_member(attribute)/memeber_function(methid).*/

    s1.roll_no=1;

    s1.welcome();
    cout<<endl;


    /*Printing the initialized value of class member.*/
    cout<<s1.name<<" "<<s1.roll_no<<endl;

    return 0;
}