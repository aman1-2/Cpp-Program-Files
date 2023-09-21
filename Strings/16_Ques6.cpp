/*WAP Given a binary string and an integer k,return the maximum number of conseutive 1's 
in the string if you can flip at most k 0's.

INPUT:- str="0001101011" , k=2
OUTPUT:- 7

Time Complexity -> O(n) ,where n is the size of the inputed string.
Space Complexity ->O(1)

*/

#include<bits./stdc++.h>
using namespace std;
int maxConsecutiveOne(string str,int num);
int main(){
    string str;
    int num;
    cout<<"Enter your binary string: ";
    getline(cin,str);
    cout<<"Enter the number of Zero's we can swap: ";
    cin>>num;

    /*Here we have created a function maxConsecutiveOne to find out the longest one series
    of the binary string.*/
    int res=maxConsecutiveOne(str,num);
    cout<<"The maximum consecutive one in the binary string is: "<<res;

    return 0;
}

/*In this function we have used ->  WINDOW SLIDING TECHNIQUE
We have created two pointers one starting and other ending pointer to have the track of the
possible potential substr the starting and ending pointers are initialized with 0.

Now we traverse through our binary string till our ed pointers reaches the end of the string
if our ed position character is equal to zero then we have to increment our zero_count
and if the ed character is not equal to zero then see whether the zero_count has increased
the value of num or not if it has increased the value of num in that case we have to shrink
our substracting or window i.e now we have to move our starting pointer till the zero_count is
either equal or less than num.In hand while moving the start pointer go on checking if we
are loosing any zero then we have to update the zero_count i.e if the start pointer is
pointing to zero then decrement the zero_count.Once achived the zero_count<=num.

Our next step is too update our max_lenght value by choosing the max value from the past given
value and the length of the current substring which could be found by subtracting (ed-st+1).

And the last step to update our end pointer.
*/
int maxConsecutiveOne(string str,int num){
    int zero_count=0,max_length=0,st=0,ed=0;
    while(ed<str.length()){
        if(str[ed]=='0'){
            zero_count++;
        }
        
        while(zero_count>num){
            if(str[st]=='0')    zero_count--;
            st++;//Contracting our window.
        }

        //This step will be approached only if the zero_count is less than num or equal to it.
        max_length=max(max_length, ed-st+1);
        ed++;
    }

    return max_length;
}