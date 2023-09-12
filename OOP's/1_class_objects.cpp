/*WAP where you declare an objectband define a class??
Basically you try ti=o expalin objects and class.*/

#include<bits/stdc++.h>
using namespace std;

//Defining a class with the help of a class keyword.
class student{ //Student is class name.
//By default the access specifier of a class is private.

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

    //So student is a class and s1 is its object

    return 0;
}