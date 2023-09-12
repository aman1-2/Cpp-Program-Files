/*Linear Search Algorithm -> In linear search we try to find the element from the group of
data by checking the every element of the group whether its equal to the elemnet or not if 
its equal to the search element then the index of that element is returned otherwise -1
which states that element is not present in the vector....*/

#include<iostream>
using namespace std;
int searching(int arr[],int num,int search); //Searching Function
int main()
{
    int num,count=1,search;
    cout<<"Enter the number: ";
    cin>>num;
    int arr[num];
    for(int &ele:arr){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<endl;
    cout<<"Enter the number you want to search from the vector: ";
    cin>>search;
    cout<<endl;
    int res=searching(arr,num,search);
    if(res==-1) cout<<"The Element you have passed is not present in the vector.";
    else    cout<<"The index of the element "<<search<<" is "<<res;
    return 0;
}
int searching(int arr[],int num,int search){
    //Iterating through every element of the element
    for(int i=0;i<num;i++){
        //Checking if the element is equal to search element or not
        if(arr[i]==search)  return i; //If its equal then the index of that element is 
        //returned there only and the searching is stopped
    }
    return -1; /*If we have iterated our whole vector or data passed and search element
    is not present in our data or vector in that case we just return -1 which idicate the
    absemce of the element in our data or vector......*/
}