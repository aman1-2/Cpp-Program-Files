/*WAP You are given two strings s and t, determine if they are isomorphic or not.

Isomorphic -> one-one mapping(Every element should be mapped to an element).

Isomorphic terms are one-one character that is one character linked with another character 
must always like with the same character like egg and add
e->a g->d e and g or a and d are mapped to the same type of character.

INPUT:- s=egg   t=add
OUTPUT:- yes

Time Complexity->O(n) ,where n is the length of the string.
Space Complexity->O(256) ,where 256 always remains constant.

*/

#include<bits/stdc++.h>
using namespace std;
bool isomorphic(string str1,string str2);
int main(){
    string str1,str2;
    cout<<"Enter a string str1: ";
    getline(cin,str1);
    cout<<"Enter a string str2: ";
    getline(cin,str2);

    /*To check if the strings are isomorphic or not we have createda function isomorphic.*/
    if(isomorphic(str1,str2))   cout<<"The strings given are Ismorphic.";
    else    cout<<"The strings given are not Ismorphic.";

    return 0;
}

/*Isomorphic function..*/
bool isomorphic(string str1,string str2){

    /*Here we have created two vectors for both of our string since we have to check the 
    mapping of the character then we will have to store unique value at the characters
    position and nothing better and unique can be rather than the original index of the 
    characters in their actual string.
    If both the indexes matches then the characters are mapped to thier right characters
    and if the indexes does'nt matches then the charcaters are not mapped to their right
    character.
    To check whether they are isomorphic or not we have to check if the characters index
    are matched rightly or not if the index matches then the characters are mapped to their
    characters.
    */

    vector<int>freq1(128,-1);
    vector<int>freq2(128,-1);

    /*Every character must be mapped and must be mapped to a unique character is the 
    condition for the isomorphic characters.*/
    if(str1.length()!=str2.length())    return false;

    int i=0,j=0;//Two pointers too iterate two strings.
    while(i<str1.length() and j<str2.length()){
        //Checking if the value of character at idx i matches in both vectors
        if(freq1[str1[i]]!=freq2[str2[j]])    return false;
        else{
            //storing string position in vector for characters at idx i
            freq1[str1[i++]]=i;
            freq2[str2[j++]]=j;
        }
    }

    return true;
}

// bool isomorphic(string str1,string str2){
//     if(str1.length()!=str2.length())    return false;

//     vector<int>freq1(26,-1);
//     vector<int>freq2(26,-1);
    
    
    /*In This for loop we have taken an i pointer variable that traverses both the strings
    and checks the matching of the elemets in the vector.*/

//     for(int i=0;i<str1.length();i++){
//         if(freq1[str1[i]-'a']!=freq2[str2[i]-'a']) return false;
//         else{
//             freq1[str1[i]-'a']=freq2[str2[i]-'a']=i;
//         }
//     }

//     return true;
// }