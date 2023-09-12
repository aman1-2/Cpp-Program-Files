#include<bits/stdc++.h>
using namespace std;

class sum{
public:
    void add(int x, int y){
        int sum=x+y;
        cout<<sum<<endl;
    }

    void add(int x,int y,int z){
        int sum=x+y+z;
        cout<<sum<<endl;
    }

    void add(float x,float y){
        float sum=x+y;
        cout<<sum<<endl;
    }
};

int main(){

    sum s;
    s.add(2,3);
    s.add(2,3,4);
    s.add(float(2.3), float(2.7));

    return 0;
}

/*Polymorphism -> Ability of objects and methods to take different forms.
We have two types of Polymorphism as:-
(i)Complite time
(ii)Run time*/