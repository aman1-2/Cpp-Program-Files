#include<iostream>
#include<string> //A string in c++ is included with the help of <string> header file
using namespace std;
int main()
{
    string str="This is my first string in c++";
    cout<<str;cout<<endl;
    string str1("Just an another way to represent a string in the c++");
    cout<<str1;cout<<"\n\n";

    //String's definition:-
    string def("String is a sequence(or collection) of the character.");
    cout<<def;

    /*About String -> string variables are the objects of the std::string class
    strings is actually a class whereas string variables are its object. */

    cout<<"\n\n";

    cout<<"String Example:-"<<endl;
    string str2="Aman",str3="Pratap",str4="Singh";
    cout<<str2<<" "<<str3<<" "<<str4<<endl;

    /*Just one more way to give string value if we haven't included the string header file 
    or the namespace std in that case we can use this format to give another string.*/
    std::string str5="Hello";
    cout<<str5<<endl;
    return 0;
}