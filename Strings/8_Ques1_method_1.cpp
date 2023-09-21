/*Given a string,sort the given string
Constraints:-The string will contain only alphabetical character from a-z

Input 1:"codingwallah"
Output 1: "aacdghillnow"
Input 2: "star"
Output 2: "arst"

Time Complexity ->O(n) where n=length of the string.
Space Complexity ->O(26) = O(1) as 26 is going to always remain same and does'nt changes with change in input.
*/

#include<bits/stdc++.h>
using namespace std;
string sort(string &str);//This function is to sort the string in lexicographical order(alphabetical order)
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    
    cout<<"The Original String is: "<<str<<endl;
    string res=sort(str);
    cout<<"The Sorted String is: "<<res;
    return 0;
}
string sort(string &str){//This sorting is just similar as count sort with few changes in it.
    /*Creating a frequency vector.
    Now we know there are 26 alphabet hence a frequency vector of 26 size is created.*/
    vector<int>freq(26);

    //Adding elements in the frequency vector.
    for(int i=0;i<str.length();i++){//Traversing the string from starting till the ending of the string.
        int index=str[i]-'a';//Finding the position(or index) of the string in the frequency vector.
        /*Here we are subtracting the index of string with 'a' this is because we have created the
        vector of size 26 therefore the alphabet a should get the place 0 b->1 like this z->25
        whereas the original Ascii value of a is 97.
        If we won't use this method than an vector of size 122 would be created as the maxEle index
        of alphabet would be z->122 and the vector space from 0 to 96 would be wasted as we have 
        to use values from 97 to 122 therefore we are using this method in which we subtarct the
        value of 'a' from every string index which would give us the value ranging between 0 to 26.*/
        
        freq[index]++;//Later on we are just going on increasing the frequency of the element.
    }


    //Sorting the string.Since we don't need to check its stability hence we can have this approach.


    int j=0;//Actual sorted string index to store the sorted string or to place the sorted string value in it.

    /*Here we don't have to worry about the stability of the alphabets hence we can start
    with starting till the end since we have 26 elements to arrange in sorted string.We 
    just have to iterate our loop 26 times.*/
    for(int i=0;i<26;i++){

        /*Since are going on decreasing the value of frequency till the time frequency is not
        0.The while condition will always be true and goes on adding the element in the string 
        specified number of times
        Any number except 0 given in the while condition is considered true.*/

        while(freq[i]--){
            /*The same Alphabet goes on increasing till the time the freq index does'nt
            becomes zero.*/
            str[j++]=i+'a';
        }
    }
    
    return str;
}