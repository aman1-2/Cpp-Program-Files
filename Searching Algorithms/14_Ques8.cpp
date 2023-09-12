/*WAP A peak Element is an element that is strictly greater than its neighbours.
Given a 0-indexed integer array nums.Find a peak element,and return its index.If the array 
contains multiplie peaks,return the index to any of the peaks.You may imagine that
num[-1]=num[n]=-infinite. In other words,an element is always considered to be strictly
greater than a neighbours that is outside the array???

INPUT:- Array=[1,2,1,2,6,10,3]

OUTPUT:- Either index 1 or index 5 are correct output.At index 1,2 is the peak element and
at index 5,10 is the peak element.*/

#include<bits/stdc++.h>
using namespace std;
int peakElement(vector<int>&vec);
int main()
{
    int num,count=0;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    int res=peakElement(vec);
    cout<<"The peak element is: "<<res;
    return 0;
}
int peakElement(vector<int>&vec){
    /*Defining the search space from start till the end and too creating a ans variable that
    is going to store the index of the peak element*/
    int starting=0,ending=vec.size()-1;

    //Checking a condition if our starting is less than or equal to the ending then only              run the loop.
    while(starting<=ending){

        //Finding out the mid value
        int mid=starting+(ending-starting)/2;

        //Firstly testing our two boundary cases when the elements are at boundary.

        /*If the mid value comes out to be 0 in that case 0 is the starting of our array or starting
        of our mountain therefore there wont't be any element on its left side and we have to check
        its right side only.*/
        if(mid==0){
            /*if right side element is less than mid then return the 0 index.*/
            if(vec[mid]>vec[mid+1]) return 0;
            else return 1;//Otherwise return index 1.
        }
        /*Whereas if the mid element is our last element in that case we won't have any
        element at its right side.*/
        else if(mid==vec.size()-1){
            /*And if the mid element is greater than its left side return size-1.*/
            if(vec[mid]>vec[mid-1]) return vec.size()-1;
            else    vec.size()-2;//Otherwise return size-2.
        }
        else{
            /*Whereas if the mid value is greater than (mid+1) and (mid-1) then just return mid*/
            if(vec[mid]>vec[mid+1] and vec[mid]>vec[mid-1]) return mid;
            else if(vec[mid]>vec[mid-1])    starting=mid+1;//Otherwise apply the peak normal conditions if the mid element is on increasing curve shift start value.
            else    ending=mid-1;//And if the mid element is on decreasing curve then shift your ends value.
        }
    }
    return -1;
}