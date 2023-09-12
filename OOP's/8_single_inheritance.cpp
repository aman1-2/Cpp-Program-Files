#include<bits/stdc++.h>
using namespace std;

class parent{
public:
    parent(){
        cout<<"Parent class"<<endl;
    }
};

class child:public parent{
public:
    child(){
        cout<<"Child Class"<<endl;
    }
};

int main(){
    child c;

    return 0;
}
/*In a Single Inheritance a child class inherit the properties of parent class
Just like a son inheriting the properties if his father.
When their is only one parent from where the child has inherited the property then its called
single inheritance...*/