#include<bits/stdc++.h>
using namespace std;
class student{

    int scholar_id;
    string name;
    bool fee_paid;

public:

    void set(int id,string stu_name,bool fee){
        scholar_id=id;
        name=stu_name;
        fee_paid=fee;
    }

    void getScholarId(){
        cout<<"Student scholar id is: "<<scholar_id<<endl;
    }

    void getStudentName(){
        cout<<"Student Name is: "<<name<<endl;
    }

    void getFeeStatus(){
        cout<<"Student's fee status is: "<<fee_paid<<endl;
    }


    /*Explaining Constructor and its different types:-
    We have three different types of constructor's they are as follow
    (i)Default Constructor
    (ii)Parametrized Constructor
    (iii)Copy Constructor */



    //Defining a Default Constructor->
    student(){
        scholar_id=0;
        name="Give your name like: Aman";
        fee_paid=false;
    }

    /*A constructor is a type of function only with no return value defalut constructor gets
    automatically called for us by the compiler 
    A constructor with just the class name and no parameter in called default constructor..
    Inside the default constructor we can write the code which we want to implement*/




    //Second Type of Constructor is Parametrized Constructor->
    student(int id,string stu_name,bool fee){
        scholar_id=id;
        name=stu_name;
        fee_paid=fee;
    }
    /*A constructor in which we pass few arguments or parameters is called parametrized
    constructo.*/




    //Third type is Copy Constructor->
    /*A Copy constructor is used to create the copy of an object(i.e initilaizes the value of
    one object with the another object of the same class)
    We have two types of Copy Constructor as:-
    (a)Default Copy Constructor
    (b)User-Defined Copy Constructor*/

    student(student &c){
        scholar_id=c.scholar_id;
        name=c.name;
        fee_paid=c.fee_paid;
    }



    /*Whenever we create a Constructor our Destructor it too called automatically to earse
    that used memory after its use...
    A destructor is created with the help of ~(tilde sign) at the starting of the constructor.*/
    ~student(){
        cout<<"Called Destructor."<<endl;
    }

    /*We can too call our destructor Explicitly-> with the help of delete keyword..*/
};

int main(){
    student s1;
    /*When we have just declared a object and tried to print the values in this case the
    default values mentoined inside the default constructor gets applied otherwise it would
    be leaved in the case we haven't defined defalut constructor explicitly.*/
    s1.getScholarId();
    s1.getStudentName();
    s1.getFeeStatus();

    cout<<endl;

    //Calling a Parametrized Constructor....
    student s2(623,"Money",1); //A parametrized Constructor is defined for new object..
    s2.getScholarId();
    s2.getStudentName();
    s2.getFeeStatus();

    
    student s3;
    s3.set(12,"Aman Pratap Singh",0);
    student s4(s3); //Calling of the Copy Constructor...
    
    cout<<"\nPrinting the values of S3:-"<<endl;
    s3.getScholarId();
    s3.getStudentName();
    s3.getFeeStatus();

    cout<<"\nPrinting the values of S4:-"<<endl;
    s4.getScholarId();
    s4.getStudentName();
    s4.getFeeStatus();

    cout<<endl;

    student* s5 = new student();
    s5->getScholarId();
    s5->getStudentName();
    s5->getFeeStatus();

    delete s5; //Called our Destructor Explicitly...

    return 0;
}