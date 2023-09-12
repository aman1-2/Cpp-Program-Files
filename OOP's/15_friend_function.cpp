#include<bits/stdc++.h>
using namespace std;

//Trying to Explain how our friend function actually works...

class student{
    int id;
    string name;
    bool fee;

public:
    void set(int stu_id,string stu_name,bool fee_status){
        id=stu_id;
        name=stu_name;
        fee=fee_status;
    }

    void getStuDetail(){
        cout<<"Students id is: "<<id<<endl;
        cout<<"Student name is: "<<name<<endl;
        cout<<"Student fee status: "<<fee<<endl;
    }

    friend;

    /*This code look's like what is new in this the methods defined inside a function can
    easily access*/

};

class employee{
    int id;
    string name;
    char category;

public:
     void set(int emp_id,string emp_name,char emp_category){
        id=emp_id;
        name=emp_name;
        category=emp_category;
    }

    void getEmpDetail(){
        cout<<"Students id is: "<<id<<endl;
        cout<<"Student name is: "<<name<<endl;
        cout<<"Student fee status: "<<category<<endl;
    }
};

int main(){
    student stu;
    stu.set(12,"Aman Pratap Singh",1);
    stu.getStuDetail();



    return 0;
}