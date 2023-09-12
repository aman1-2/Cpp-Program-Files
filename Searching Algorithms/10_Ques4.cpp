/*WAP where you are given a sorted array is sorted array on which rotation operation
has been performed some number of times.Given a rotated sorted array.Find the index of the
minimum element in the array.Follow 0 based indexing.
It is guaranteed that all the elements in the array are unique.
INPUT:- Array={3,4,5,1,2}
OUTPUT:- 3*/

#include<bits/stdc++.h>
using namespace std;
void rotation(vector<int>&vec,int times);
void reversal(vector<int>&vec,int starting,int ending);
int searching(vector<int>&vec);
int main(){
    int num,count=0,times;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<endl;
    cout<<"Enter the number of times you want to rotate the array/vector: ";
    cin>>times;
    rotation(vec,times);
    int res=searching(vec);
    cout<<"Give the index of the minimum element: "<<res;
    return 0;
}

void rotation(vector<int>&vec,int times){
    if(times>vec.size())    times=times%vec.size();

    reversal(vec,0,vec.size());
    reversal(vec,0,times);
    reversal(vec,times,vec.size());

    return;
}

void reversal(vector<int>&vec,int strating,int ending){
    for(int i=strating,j=ending;i<j;i++,j--)    swap(vec[i],vec[j]);
    return;
}

int searching(vector<int>&vec){
    /*If we have only one element in the array in that case return zero only.*/
    if(vec.size()==1)   return 0;

    int starting=0,ending=vec.size()-1;

    /*If my starting value is less then my ending value this means my array isn't rotated
    or after the rotation has come into its original way which is a sorted array as per the 
    instruction given in the array.And a sorted array has its minimum element at starting only.*/
    if(vec[starting]<vec[ending]) return starting;

    /*Otherwise we will go for our search process*/
    while(starting<=ending){ 
        //Calculating the mid value which we normally do in our binary search operation.
        int mid=(starting+ending)/2;
        /*Now if the value of mid is more than mid+1 in that case our minimum element will
        mid +1 its because we are getting a rotated element and if the value on the right
        hand side is small this indicate that we our on the maximum value hence the minimum
        will be just after it as that right position wouldn't have experienced the rotation.*/
        if(vec[mid]>vec[mid+1]) return mid+1;

        /*Whereas if the mid-1 value is greater than mid in that case too the mid will be
        minium as rotation hasn't yet take place here.*/
        if(vec[mid]<vec[mid-1])    return mid;

        //But now if these situaton doesn't occur then we reduce our array according to these conditions
        if(vec[mid]>vec[starting]) starting=mid+1;
        else    ending=mid-1;
    }

    return -1;
}