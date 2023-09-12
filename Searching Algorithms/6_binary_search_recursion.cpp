#include<bits/stdc++.h>
using namespace std;
int searching(vector<int>&vec,int search,int starting,int ending);
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
    int res=searching(vec,search,0,vec.size()-1);
    if(res==-1) cout<<"The element you are searching in the vector isn't present over here.";
    else    cout<<"The index of "<<search<<" in the vector is: "<<res;
    return 0;
}
int searching(vector<int>&vec,int search,int starting,int ending){
    //Base condition
    if(starting>ending)    return -1;

    //Self-work to find the mid
    int mid=starting+(ending-starting)/2;

    //Checking condition if mid element is equal to search return the the mid index.
    if(vec[mid]==search)    return mid;
    else if(vec[mid]<search)    return searching(vec,search,mid+1,ending); //Recursive call
    else    return searching(vec,search,starting,mid-1); //Recursive call
    //Recursive calls are made after a condition check.
}