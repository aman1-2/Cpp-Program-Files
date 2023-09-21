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
*/

#include<bits/stdc++.h>
using namespace std;
string prefix(vector<string>&vec);
int main()
{
    int num,count=1;
    cout<<"Enter the number of strings you want in your vector: ";
    cin>>num;
    vector<string>vec(num);
    for(string &ele:vec){
        cout<<"Enter the "<<count++<<" string: ";
        cin>>ele;
    }
    
    /*Perfix function is used to find the common longest prefix.*/
    string res=prefix(vec);
    if(res=="") cout<<"We haven't found any common prefix in the vector.";
    else    cout<<"The longest common prefix is: "<<res;

    return 0;
}
string prefix(vector<string>&vec){

    /*Sorting the vector of string in lexciographical order with the help of in-bulit 
    sort function.*/
    sort(vec.begin(),vec.end());

    /*After sorting we will extract the first and last string of the vector because they will have
    most (or greatest) chance of mismatch of characters so till the starting character that 
    goes on matching in these two string will only be the longest common prefix in all the
    other strings too.*/

    /*To store the longest common prefix we have created a ans string.
    Whereas the first and last string of the vector are stored in the string str1 and str2.*/
    string ans="";
    string str1=vec[0];
    string str2=vec[vec.size()-1];
    /*We have taken too pointers that will iterate through our string.*/
    int i=0,j=0;

    /*Till the time our i and j value is less than the length of the string str1 and str2
    respectively run the while loop.*/
    while(i<str1.length() and j<str2.length()){
        /*If both the character in the string str1 and str2 are same that go on adding 
        that character in our ans string till the time we find our matching elements.
        After adding the character in the ans string go on increasing the value of our 
        pointer.*/
        if(str1[i]==str2[j]){
            ans+=str1[i];
            i++,j++;
        }
        else    break;
        /*And if the character are not same there only break the loop as we don't have to
        move forward after this and last return the ans string.*/
    }


    /*This is a self created while loop for solving the above problem if we will use this 
    then we don't have to create two string str1 and str2 to store the last and first 
    string instead we can compare the strings directly from the vector only.*/


    // while(i<vec[0].size() and j<vec[vec.size()-1].size()){
    //     if(vec[0][i]==vec[vec.size()-1][j]){    
    //         ans+=vec[0][i];
    //         i++,j++;
    //     }
    //     else    break;
    // }

    return ans;
}