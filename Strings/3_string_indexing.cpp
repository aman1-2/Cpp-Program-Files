/*Srings are Indexed in somewhat same manner as we have indexing in the array's
Strings are too 0-based index.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);cout<<endl;

    //Acessing the position of the string.........
    cout<<"Let's have a look what is present at the 2 position or what is 3rd character: ";
    cout<<str[2]<<"\n\n";

    //Updating the position of the string or the whole string.......
    cout<<"Lets update the a charater of the string:-"<<endl;
    cout<<"Original String: "<<str<<endl;
    str[0]='b';
    cout<<"Updated String: "<<str<<endl;
    str="aditya";
    cout<<"Updated String: "<<str<<endl;

    /*Lets have the look on the ASCII values */
    char ch='a';
    cout<<"\n\nPrint the Ascii value of 'a': "<<int(ch);

    return 0;
}