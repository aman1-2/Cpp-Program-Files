/*Progrsm to input a string */
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    /*We usually use cin operator to insert a value and same we can use for string too
    the only drawback in cin is the extraction operator which we use with cin i.e'>>'
    terminates as it encounters any white space(space,tab,new line) it treats it as the 
    teminating character.*/

    // string str;
    // cout<<"Enter a string with normal cin operator: ";
    // cin>>str;
    // cout<<str;cout<<endl;



    /*To overcome this problem we have getline function of the string that takes the 
    whole string with all special characters and spaces in it.*/
    string str1;
    cout<<"Enter the string with getline function: ";
    getline(cin,str1);
    cout<<str1; 
    
    /*Whereas in the c programming we have get() finction to take string input.*/
    
    return 0;
}