/*Writing the implementation of the few mostly used functions of the string.*/

#include<bits/stdc++.h>
using namespace std;
int main(){

    /*size() -> It is used to find out the size of the string that how many characters are
    present in the string.
    we can too use length function for this.*/
    string str1;
    cout<<"Enter a string: ";
    getline(cin,str1);
    cout<<"Print the size of the string: "<<str1.size()<<endl;
    cout<<"Print the length of the string: "<<str1.length()<<endl;



    /*strlen(character_array_name) -> It is used to count the number of characters 
    present in the character array just like the size and length function of the string.
    The only difference is that strlen() is used for character array whereas the size()
    and length() functions are used for strings.*/

    char arr[20];
    cout<<"Enter a Character array: ";
    cin>>arr;
    cout<<"Printing the size or length of the character array: "<<strlen(arr);

    return 0;
}
