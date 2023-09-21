/*Writing the implementation of the few mostly used functions of the string.*/

#include<bits/stdc++.h>
using namespace std;
int main(){

    /*push_back(ch) -> Push back is used to append a character at the end of the string.*/
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    char ch;
    cout<<"Enter the character to be appended: ";
    cin>>ch;
    str.push_back(ch);
    cout<<"Printing the the string with the appended character: "<<str;
    
    return 0;
}