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

class grandchild:public child{
public:
    grandchild(){
        cout<<"Grand-child class"<<endl;
    }
};

int main(){
    grandchild gc;

    return 0;
}
/*In multi-level inheritance a child class inherit the property of a class which has itslef
inherited some property from his parent class.

Like a son inherit the property from his father and father has inherited the property from
grand-father in this case the son will have the propery of father as well as grand-father.*/