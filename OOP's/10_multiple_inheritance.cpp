#include<bits/stdc++.h>
using namespace std;


class parent1{
public:
    parent1(){
        cout<<"Parent1 class"<<endl;
    }
};

class parent2{
public:
    parent2(){
        cout<<"Parent2 class"<<endl;
    }
};

class child:public parent1, public parent2{
public:
    child(){
        cout<<"Child Class"<<endl;
    }
};

int main(){
    child c;

    return 0;
}
/*Multiple inheritance is when a class inherits the property from more than one class.
Just like we have inherited the properties from your parents.
One thing to note here is that the parent defined first will be inherited first.*/