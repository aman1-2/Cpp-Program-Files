/*An encoded string s is given,and the task is to decode it.The encoding pattern is that
the occurence of the string is given at the starting of the string and each string is 
enclosed by square brackets.

Note:-The occurence of a single string is less than 1000.

INPUT:- s=1[b]
OUTPUT:- b

INPUT:- s=3[b2[ca]]
OUTPUT:- bcacabcacabcaca

Time Complexity ->O(n) ,where n is the length of our decoded string.As in the last while we are concatenating the decoded
string in our result string.
Space Complexity ->O(n) ,Where n is the length of the decoded string as the we have created a result string to store 
are decoded string.

*/

#include<bits/stdc++.h>
using namespace std;
string decode(string s);
int main(){
    string str;
    cout<<"Enter the Encoded string: ";
    getline(cin,str);

    cout<<"The Decoded String: "<<decode(str)<<endl;

    return 0;
}

/*(i)We have firslty created a string result in which we are appending(inserting) the encoded
string till we get the first ']' closing bracket as we have to start our decoding from the
first encounterd character.
Traversing the encoded string and appending the elements in our result string.

(ii)Extracting str string from result in this we will extarct the character that we have
to repeat.
For this our first check should be that our original string should not be empty and the 
second condition should be the last character extracting must not be '[' a opneing bracket.
Therefore we have to extarct the character till this '['.
One thing to note is that we are extracting the characters in backward direction therefore 
the string str which we will get will actual have the characters in reverse order.

(iii)Reverse the string to have it in right way.

(iv)Remove the last charcter which will be '[' when we will extract all the character this
will be left and we have to remove it.

(v)Our next step is to extract the num.
To extract the num we will create a string num and in this the condition should be our
result string must not be empty and the result string last element must be a num character
and must range between '0' and '9'.

(vi)After getting the num string it will to be in backward direction as characters are 
extracted in backward direction.Hence we have to reverse our num string too.

(vii)Convert the string num into int num.

(viii)Inserting the str string intnum times in our result.

*/
string decode(string s){

    string result="";

    //Traversing the encoded string.
    for(int i=0;i<s.length();i++){
        if(s[i]!=']'){
            result.push_back(s[i]);
        }
        else{

            //Extracting str from result
            string str="";
            while(!result.empty() and result.back()!='['){
                str.push_back(result.back());
                result.pop_back();
            }

            //Reversing the string
            reverse(str.begin(),str.end());

            //Remove last character which is '['.
            result.pop_back();

            //Extract num from result.
            string num="";
            while(!result.empty() and result.back()>='0' and result.back()<='9'){
                num.push_back(result.back());
                result.pop_back();
            }

            //Reversing the num string.
            reverse(num.begin(),num.end());

            //Convert String to Integer.
            int int_num=stoi(num);

            //Inserting str in result int_num times.
            while(int_num){
                result+=str;
                int_num--;
            }
        }
    }
    return result;
}