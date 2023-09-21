/*Given an array of strings.WAP to find the longest common prefix string amongst array of 
string.

INPUT:- arr=["flower","flight","flask"]
OUTPUT:- "fl"

Time Complexity -> O(nlogn * m) + O(min(first_string_size,last_string_size))
O(nlogn) is the time complexity that the in-built sort function takes.
And in this we have multipied it with the m which shows the time taken for the comparison of
the two strings.
(Here n indicates -> number of strings we have in our vector. whereas m indicates -> the 
actual length of the strings.)

Space Complexity -> O(1)
                           METHOD-2
*/


#include<bits/stdc++.h>
using namespace std;
string prefix(vector<string>&vec);
int main(){
    int num,count=1;
    cout<<"Enter the number of strings: ";
    cin>>num;
    vector<string>vec(num);
    for(string &ele:vec){
        cout<<"Enter the "<<count++<<" string: ";
        cin>>ele;
    }

    /*Prefix function is to find the longest common prefix.s*/
    string res=prefix(vec);
    if(res=="") cout<<"There is no common character in the string.";
    else    cout<<"The commom longest prefix is: "<<res;

    return 0;
}

string prefix(vector<string>&vec){
    /*Taking one string as constant and comparing it with all the other string.*/
    string str=vec[0];
    int subStringLength=str.size();

    for(int i=1;i<vec.size();i++){
        int j=0;/*This variable is both for the pointer use to iterate over string and also
        to find the length of the string.
        In while condition we are checking the j's values shouldn't go above the length of
        the str or the string getting compared 
        one more condition is that both the strings characters must be equal.*/
        while(j<str.length() and j<vec[i].length() and str[j]==vec[i][j]){
            j++;//If the while condition is true then increment the value of j.
        }
        subStringLength=min(subStringLength,j);//Storing the minimum common characters length.
    }

    string result=str.substr(0,subStringLength);//Taking out the substring from the str of substringlength.

    return result;
}