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

        METHOD->2 Creating a frequecy array/vector and then counting the frequecy of
        characters appering in the first string and then comapring the frequency of the
        character appering in the second string if they are equal then its an anagram and 
        if not its not an anagram.

        METHOD-3 Similar as METHOD-2 just instead of creating two different vectors/Array
        do the same thing with the help of one doing both the work simintaneously
        i.e adding the count of the character appering for the first string and subtracting
        the count of the character appering for the second string.
        And at the end if all the elements of the vector is zero then its an
        anagram and if at any place its not zero then its not an anagram.


Time Complexity -> O(n)  ,Where n is the length of the string.
Space Complexity -> O(26) ,Which will always remain constant.

*/
#include<bits/stdc++.h>
using namespace std;
bool isAnagram(string str1,string str2);
int main()
{
    string str1,str2;
    cout<<"Enter the string str1: ";
    getline(cin,str1);
    cout<<"Enter the string str2: ";
    getline(cin,str2);

    /*Made a Boolean function to check if the given strings are anagram or not.*/
    if(isAnagram(str1,str2))    cout<<"The string str2 is an anagram of the string str1.";
    else    cout<<"These two strings are not anagram of each other.";

    return 0;
}

/*Anagram Function:-*/
bool isAnagram(string str1,string str2){
    /*Firstly created an vector to store the count of the characters.
    since we have 26 alphabets hence an vector of size 26 is created.
    And initialized our vector with value 0 in it.*/
    vector<int>freq(26,0);

    /*Now for a string to be an anagram both the string should be of the same length
    so our first  condition would be to check if both the strings are equal in length if
    they are not then return false as in that scenario they will never be an anagram
    string.*/
    if(str1.length()!=str2.length())    return false;
    else{
    /*Now in the else part we are going to simintaneously add the charater and delete the 
    character as per the characters pointed in both the strings.*/
        int i=0;//j=0;//Created two pointer variables that iterates two strings.Can have only one pointer two.

        /*Checking the condition till the time both the pointer value are less then
        the string we have to run the loop.
        Here we can too give only one pointer and any string length as this loop will 
        run only when the condition both the strings having same length evalutes to true.*/

        while(i<str1.length()){   //i<str1.length() and j<str2.length()

        /*Now counting the count of characters in the string.
        For the first string we are counting the presence of character in the vector.
        And for the second string we are going subtracting that character presence
        from the vector.*/
            
            // freq[str1[i++]-'a']++;
            // freq[str2[j++]-'a']--;

            freq[str1[i]-'a']++;
            freq[str2[i]-'a']--;
            i++;//Incrementing the value of i.

        }
    }
    

    /*At the end checking if all the values of the vector are zero or not if all the values
    of the vector is zero in that case it is anagram and if at any place it is not zero then
    it is not anagram. */
    for(int i=0;i<26;i++){
        if(freq[i]!=0)  return false;
    }

    return true;
}