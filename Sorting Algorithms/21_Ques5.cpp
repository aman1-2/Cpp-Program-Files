/*WAP to merge two sorted array to make them one??......*/

#include<bits/stdc++.h>
using namespace std;
void mergeSort(int arr1[],int arr2[],int arr3[],int size1,int size2,int size3);
void output(int arr3[],int size3);
int main()
{
    int arr1[]={5,8,10},arr2[]={2,7,8};
    int arr3[3+3];
    mergeSort(arr1,arr2,arr3,3,3,6);
    output(arr3,6);
    return 0;
}
void mergeSort(int arr1[],int arr2[],int arr3[],int size1,int size2,int size3){
    int i=0,j=0,k=0;
    while(i<size1 and j<size2){
        if(arr1[i]<arr2[j]) arr3[k++]=arr1[i++];
        else    arr3[k++]=arr2[j++];  
    }
    while(i<size1)  arr3[k++]=arr1[i++];
    while(j<size2)  arr3[k++]=arr2[j++];
    return;
}
void output(int arr3[],int size3){
    for(int i=0;i<size3;i++)    cout<<arr3[i]<<" ";
    return;
}