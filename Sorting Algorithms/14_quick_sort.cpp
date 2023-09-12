#include<bits/stdc++.h>
using namespace std;
void quickSort(vector<int>&vec,int starting,int ending);
int partition(vector<int>&vec,int starting,int ending);
void output(vector<int>&vec);
int main()
{
    int num,count=1;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    quickSort(vec,0,vec.size());
    output(vec);
    return 0;
}
void quickSort(vector<int>&vec,int starting,int ending){
    if(starting>=ending)    return;
    int pi=partition(vec,starting,ending);
    quickSort(vec,starting,pi-1);
    quickSort(vec,pi+1,ending);
    return;
}
int partition(vector<int>&vec,int starting,int ending){
    int pivot=vec[ending];
    int i=starting-1;
    for(int j=starting;j<ending;j++){
        if(vec[j]<pivot){
            i++;
            swap(vec[i],vec[j]);
        }
    }
    swap(vec[i+1],vec[ending]);
    return i+1;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}