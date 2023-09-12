#include<bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&vec,int size);
void output(vector<int>&vec);
int main()
{
    int num,count=1;
    cout<<"Enterthe number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    bubbleSort(vec,vec.size());
    output(vec);
    return 0;
}
void bubbleSort(vector<int>&vec,int size){
    if(size==1)  return;

    for(int i=0;i<size-1;i++){
        if(vec[i]>vec[i+1]){
            swap(vec[i],vec[i+1]);
            bubbleSort(vec,size);
        }
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}