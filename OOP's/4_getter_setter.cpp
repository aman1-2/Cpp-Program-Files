/*Getter and setters are used in objects to do some soecific tasks such as
Getter -> fetchs the value or prints the valaue of the private member of the class as private
attributs can only be accessissble within the class or inside the member function of the class...

Whereas Setter is used to set the value to the print attribute of the class...

Let's see its implementation......*/

#include<bits/stdc++.h>
using namespace std;

class student{
/*If we don't define any access specifier to our class in that the attributes are considered
private as default access specifier is Private.*/
    string name;

public: 
    /*We made a setter to set the value of the string name 
    for this we have created a function set that is setting the value of name with its parameter..*/
    void set(string n){
        name=n;
        return;
    }

    /*Whereas we will create a getter function with the name get and its purpose will be
    to extract oe fetch the value of our private member as we cann't do this directly with the
    help of dot (.) operator*/
    void get(){
        cout<<name<<endl;
        return;
    }
};

int main(){
    student s1;
    s1.set("Aman"); //Called the setter function to set the value of name(which is a private member)...
    s1.get(); //Called getter to fetch or extract the value of name(which is a priavte member)...
    return 0;
}