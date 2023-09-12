/*Binary Search -> Binary searching algorithms are used to find or search an element from
vector/array or data just by dividing the data into two equal parts and then choosing
one part where the element would be present by dicarding the other part.

Binary Search are most of the cases applied on sorted data (i.e array/vector) its not always
necessary to have a sorted data to apply the binary search.

One more thing to note is that Binary search are preformed on those sets where we can divide
the data into two parts from mid.Now its too not necessary that the data which can be divided
into two parts there we can apply binary search.To apply binary search there the right
portion of the data must be different from its left part with atleast one property.

In Binary search we actully reduce our search space till the time we have one element left
in our search space and that one element must be equal to the searh to return its index...*/

#include<bits/stdc++.h>
using namespace std;
int searching(vector<int>&vec,int search); //Searching Function
int main()
{
    int num,count=0,search;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<endl;
    cout<<"Enter the number you want to search from the vector: ";
    cin>>search;
    cout<<endl;
    int res=searching(vec,search);
    if(res==-1) cout<<"The Element you have passed is not present in the vector.";
    else    cout<<"The index of the element "<<search<<" is "<<res;
    return 0;
}
int searching(vector<int>&vec,int search){
    int starting=0,ending=vec.size()-1; //Defining the Searching space from where till where 
    // we have to search the element.

    while(starting<=ending){
        //Calculating the mid point of the data set(i.e vector).
        int mid=(starting+ending)/2;
        if(vec[mid]==search) return mid; //If equal then return the index.
        else if(vec[mid]<search) starting=mid+1; //Discard the left of the mid.
        else    ending=mid-1; //Discard the right of the mid. 
    }
    return -1; //-1 is returned if we haven't found the searched element from our search space.
}