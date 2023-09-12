#include<bits/stdc++.h>
using namespace std;

class parent{
public:
    int x;
protected:
    int y;
private:
    int z;
};

class child1:public parent{
    /*
    X will remain Public
    Y will remain Protected
    Z will be inaccessible
    */
};
class child2:private parent{
    /*
    X will remain Private
    Y will remain Pivate
    Z will be inaccessible
    */
};
class child3:protected parent{
    /*
    X will be Protected
    Y will be Protected
    Z will be inaccessible
    */
};
