/*Writing the implementation of the few mostly used functions of the string.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    //reverse() function->It is used to reverse the given string.
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    /*The reverse function reverses the string in the actual stored string variable
    Time Complexity-O(length of the string)
    Space Complexity-O(1) As it reverses the string at its original place only.*/
    reverse(str.begin(),str.end());
    cout<<"Printing the reverse of the string: "<<str;



    /*substr(starting position of sub-stroing , length of the sub-string)->
    It is used to find a sub-string from the provided string.*/
    string str1;
    cout<<"\n\nEnter the string: ";
    getline(cin,str1);
    cout<<"Original string: "<<str1<<endl;
    /*The substr extracts out a part of the string from the original provided string.
    In substr function we provide it with two parameters as the postion of the substring 
    from where we have to extract ans second is the length of the substring.
    Time complexity-O(length of the sub-string)
    Space Complexity-O(1).*/
    cout<<"Substring from the original string: "<<str1.substr(2,2)<<endl;
    /*Lets see what if we oly provided the starting position of the string and not the 
    lenght of the substring till where it has to go in that case it will print the whole string
    starting from the the starting point of the substring.*/
    cout<<"When provided only the starting value in substr(): "<<str1.substr(1);



    /*'+' operator-> It is used to concatenate two strings.*/
    string str2,str3;
    cout<<"\n\nEnter the string part 1: ";
    getline(cin,str2);
    cout<<"Enter the string part 2: ";
    getline(cin,str3);
    cout<<"Print the first part 1 of the string: "<<str2<<endl;
    cout<<"Print the second part 2 of the string: "<<str3<<endl;
    /*Now concatenating in two different ways:-
    (i)str2=str2+str3
    In this way a copy str2 will be created in which the str3 will get appended and a new
    appended string will get stroed in the str2.*/
    cout<<"Str2=str2+str3 -> "<<str2+str3<<endl;
    str2=str+str3;
    cout<<"Str2=str2+str3 -> "<<str2;
    /*Whereas an another method is
    (ii)str2+=str3
    In this case there won't be any copy of the string will form inspite of that the str3
    will direct get append at the end of str2.*/
    str2+=str3;
    cout<<"st2+=str3 -> "<<str2;



    /*strcat(character_array1,character_array2) -> It is used to concatenate the two 
    character array's.*/
    char arr1[20],arr2[20];
    cout<<"\n\nEnter the first character array: ";
    cin>>arr1;
    cout<<"Enter the second character array: ";
    cin>>arr2;
    cout<<"The concatenated character is: "<<strcat(arr1,arr2);

    return 0;
}