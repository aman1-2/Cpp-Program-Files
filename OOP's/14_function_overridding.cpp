#include<bits/stdc++.h>
using namespace std;

class parent{
public:
    virtual void print(){
        cout<<"Parent class"<<endl;
    }
    void show(){
        cout<<"Parent class"<<endl;
    }
};

class child:public parent{
public:
    void print(){
        cout<<"Child class"<<endl;
    }
    void show(){
        cout<<"Child class"<<endl;
    }
}; 

int main(){
    parent *p;
    child c;

    p=&c;
    p->print();
    p->show();

    return 0;
}
