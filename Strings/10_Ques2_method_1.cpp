/*WAP Where you are given two strings s and t. Return true if t is an anagram of s,otherwise
false
Constraints:-String s and t will contain lowercase alphabetical character.

Anagram -> Anagram word are those words which are created with the help of the exicting word
the new word is created by using the same charaters present in the exicting character same
number if times non of the character can be leaved nor an extra character can be used new 
word and exciting word must be of the same length.  

INPUT1 -> s=anagram and t=nagaram
OUTPUT1 ->Yes
INPUT2 -> s=bank t=atm
OUTPUT2 -> No.

          METHOD->1 Used the approach of sorting the string and then comparing both the
          sorted strings if they are equal then its anagarm.


Time Complexity -> O(n) ,where n is the length of the string.
O(n) is the time complexity of the count sort.
Space Complexity -> O(26) ,Which will always remain constant.

*/
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string str1,string str2);
string sorting(string str);
int main()
{
    string str1,str2;
    cout<<"Enter the string str1: ";
    getline(cin,str1);
    cout<<"Enter the string str2: ";
    getline(cin,str2);

    /*Made a Boolean function to check if the given strings are anagram or not.*/
    if(isAnagram(str1,str2))   cout<<"The string str2 is anagram of string str1.";
    else    cout<<"These strings are not anagram.";

    return 0;
}

/*Anagram Function:-*/
bool isAnagram(string str1,string str2){

    /*Now for a string to be an anagram both the string should be of the same length
    so our first  condition would be to check if both the strings are equal in length if
    they are not then return false as in that scenario they will never be an anagram
    string.*/
    if(str1.length()!=str2.length())    return false; 
    else if(sorting(str1)==sorting(str2))    return true;
    /*Now the else part if the strings are of equal length then you have to sort both the
    strings in lexicographical order because the anagram strings sorted string will always
    be same as(anagaram are the word made by the use of the existing words character
    we use exactly the same character same number of times used in our word tp create a
    new word) therfore anagrams sorted string will always be equal.*/

    /*For sorting the strings we have created the sorted function after which we checks if
    the sorted strings are equal or not if they are equal then return true otherwise a false.
    */

    return false;
}

/*String sorting function in lexicographical order*/
string sorting(string str){
    vector<int>freq(26,0);

    for(int i=0;i<str.length();i++) freq[str[i]-'a']++;

    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
            str[j++]=i+'a';
        }
    }

    return str;
}