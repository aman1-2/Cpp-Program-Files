/*WAP where you are given an mountain array 'a' of length greater than 3,return the index
'i' such that arr[0]<arr[1]<.....arr[i]<arr[i-1]>arr[i+1]>....>arr[length-1]. This index is known
as the peak index????
INPUT:- Array={0,4,1,0}
OUTPUT:- 1*/

#include<bits/stdc++.h>
using namespace std;
int search(vector<int>&vec);
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
    search(vec);
    int res=search(vec);
    cout<<"The peak or the mountain element is: "<<res;
    return 0;
}
int search(vector<int>&vec){
    /*Defining the search space from start till the end and too creating a ans variable that
    is going to store the index of the peak element*/
    int starting=0,ending=vec.size()-1,ans=-1;

    //Checking a condition if our starting is less than or equal to the ending then only run the loop.
    while(starting<=ending){

        //Finding out the mid value
        int mid=starting+(ending-starting)/2;

        /*Checking the mid value if its mid value is greater than mid-1 i.e its scucceding 
        element which means it is in the increasing curve*/
        if(vec[mid]>vec[mid-1]){
            /*Storing the mid value as it might be a answer for yes and discarding the left
            portion.
            
            Here we can too modify our mid statement with mid=max(ans,mid)-> this means that
            our ans variable will only store the maximum index in it for our peak element.*/
            ans=mid;
            starting=mid+1;
        }else{
            /*Discarding the right portion*/
            ending=mid-1;
        }

    }
    
    /*Returnig the index of the peak element i.e returning the value stored in our ans variable.*/
    return vec[ans];//Actually we just returned the peak element from our mountain array.

}