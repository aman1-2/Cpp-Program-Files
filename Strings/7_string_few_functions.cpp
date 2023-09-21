/*Writing the implementation of the few mostly used functions of the string.*/

#include<bits/stdc++.h>
using namespace std;
int main(){

    /*to_string(<value>) -> It is used to convert a numeric or interger value into the string.*/
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    string str=to_string(num);
    cout<<"string="<<str;

    return 0;
}