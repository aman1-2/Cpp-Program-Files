#include<iostream>
using namespace std;
void insertionSort(int arr[],int size);
void insertionSortWhile(int arr[],int size);
void output(int arr[],int size);
int main()
{
    int num,count=1;
    cout<<"Enter the number: ";
    cin>>num;
    int arr[num];
    for(int &ele:arr){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    insertionSort(arr,num);
    output(arr,num);
    cout<<endl;
    insertionSortWhile(arr,num);
    output(arr,num);
    return 0;
}
void insertionSort(int arr[],int size){
    for(int i=1;i<size;i++){
        int currentEle=arr[i],j=i-1;
        while(j>=0 and arr[j]>currentEle){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=currentEle;
    }
    return;
}
void output(int arr[],int size){
    for(int i=0;i<size;i++)     cout<<arr[i]<<" ";
    return;
}
void insertionSortWhile(int arr[],int size){
    cout<<"While:-"<<endl;
    int i=1;
    while(i<size){
        int currentEle=arr[i],j=i-1;
        while(j>=0 and arr[j]>currentEle){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=currentEle;
        i++;
    }
    return;
}