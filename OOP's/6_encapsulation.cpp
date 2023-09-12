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
};

/*With the Help of classes we can encaplsulate our data that is we can bind our data with
the member function and the attributes presen tin the class...
When we bind in that case our private data of the class is only accesible through the member
functions of that class only....*/

int main(){
    student s1;
    s1.set(12,"Aman",1);
    s1.getStudentName();
    s1.getScholarId();
    s1.getFeeStatus();

    return 0;
}