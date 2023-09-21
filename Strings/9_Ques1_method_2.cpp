/*Given a string,sort the given string
Constraints:The string will contain only alphabetical character from a-z

Input 1:"codingwallah"
Output 1: "aacdghillnow"
Input 2: "star"
Output 2: "arst"

Time Complexity ->O(n) where n=length of the string.
Space Complexity ->O(26) = O(1) as 26 is going to always remain same and does'nt changes with change in input.
*/

#include<bits/stdc++.h>
using namespace std;
string sorting(string str);
int main(){
    string str;
    cout<<"Enter the String: ";
    getline(cin,str);
    cout<<"The Original String is: "<<str<<endl;
    string res=sorting(str);
    cout<<"Sorted String is: "<<res<<endl;
    return 0;
}

/*Here we are completely going to use the count sort method to sort teh string in the
lexicographical order.*/
string sorting(string str){
    /*Firslty taking the frequency array of 26 length as ther are 26 alphabets.We will be 
    subtracting character 'a' from the current string characters ascii value so that we
    can fit it within the range of 0-25.*/
    vector<int>freq(26,0);

    /*Adding values to the frequwncy vector.
    Then creating a cumulative vector to maintain its stability too.*/
    for(int i=0;i<str.length();i++) freq[str[i]-'a']++;
    for(int i=1;i<26;i++)   freq[i]+=freq[i-1];

    //After this created an ans string variable to store our ans.
    string ans="";

    /*Adding the elements into our ans string from backward direction to maintain the 
    stability.The string character one by one will be placed at the right position 
    in the ans string*/
    for(int i=str.length()-1;i>=0;i--)  ans[--freq[str[i]-'a']]=str[i];

    //At last copying the ans string chan=racter one by one in the original string
    for(int i=0;i<str.length();i++) str[i]=ans[i];

    //At last returning the string str.
    return str;
}