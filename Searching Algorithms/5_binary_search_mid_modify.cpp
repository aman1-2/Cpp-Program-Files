/*This searching algorithm looks good and perfect to us but still it has some flaws(faults)
in it and its the way we are calculating the mid value.

We are calculating the value of mid = (starting + ending)/2 which is absolutely correct
this gives us right answer.Then that's the problem in it.So problem is if our starting value
is some maximum value of integer say INT_MAX and our ending value is too say some maximum
value lets say it is too INT_MAX in that case they both are storing the maximum value and
since to calculate the mid we are adding our starting and ending value which are holding 
INT_MAX value in it in that case our int range will go out of bounce and variable won't be
able to hold such a large value in it.

To overcome this problem we can either make our mid as unsigned integer in that case its
range will increase beacuse it will only hold positive value but that too it will work to 
some extent it isn't absolutely correct way......

The most correct way is by using this formula of mid ->
mid = starting + (ending-starting)/2 [The computated result will be much smaller than our INT_MAX as firstly we are subtracting it and then dividing it by 2.]
So here we are adding a small vlaue in our start to reach the mid

Let's have a look over its prove 
mid = (starting+ending)+starting-starting/2 [subtracting and adding starting will not make any difference.]
mid = (starting+starting+ending-starting)/2
mid = 2(starting)/2 + (ending-starting)/2
mid = starting + (ending-starting)/2   */


#include<bits/stdc++.h>
using namespace std;
int searching(vector<int>&vec,int search);
int main(){
    int num,count=0,search;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<endl;
    cout<<"Enter the element you want to search from the vector: ";
    cin>>search;
    cout<<endl;
    int res=searching(vec,search);
    if(res==-1) cout<<"The element you are searching in the vector isn't present over here.";
    else    cout<<"The index of "<<search<<" in the vector is: "<<res;
    return 0;
}
int searching(vector<int>&vec,int search){
    int starting=0,ending=vec.size()-1;

    while(starting<=ending){
        //Calculating the mid value with the modified way.
        unsigned int mid=starting+(ending-starting)/2;

        if(vec[mid]==search)    return mid;
        else if(vec[mid]<search)    starting=mid+1;
        else    ending=mid-1;
    }
    return -1;
}