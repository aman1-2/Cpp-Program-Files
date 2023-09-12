#include<iostream>
using namespace std;
void bubbleSort(int arr[],int size);
void output(int arr[],int size);
void bubbleSortWhile(int arr[],int size);
void bubbleSortFullWhile(int arr[],int size);
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
    bubbleSort(arr,num);
    output(arr,num);
    cout<<endl;
    bubbleSortWhile(arr,num);
    output(arr,num);
    cout<<endl;
    bubbleSortFullWhile(arr,num);
    output(arr,num);
    return 0;
}
void bubbleSort(int arr[],int size){
    cout<<"Bubble Sorting:-"<<endl;
    for(int i=0;i<size-1;i++){
        bool flag=false;
        for(int j=0;j<(size-1)-i;j++){
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!flag)   break;
    }
    return;
}
void output(int arr[],int size){
    for(int i=0;i<size;i++)     cout<<arr[i]<<" ";
    return;
}
void bubbleSortWhile(int arr[],int size){
    cout<<"Partial While:-"<<endl;
    int i=0;
    while(i<size-1){
        bool flag=false;
        for(int j=0;j<(size-1)-i;j++){
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(!flag)   break;
        i++;
    }
    return;
}
void bubbleSortFullWhile(int arr[],int size){
    cout<<"Fully-While:-"<<endl;
    int i=0,j=0;
    while(i<size-1){
        bool flag=false;
        while(j<(size-1)-i){
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j],arr[j+1]);
            }
            j++;
        }
        if(!flag)   break;
        i++;
    }
    return;
}