#include<bits/stdc++.h>
using namespace std;
void mergeSort(vector<int>&vec,int starting,int ending);
void merge(vector<int>&vec,int starting,int mid,int ending);
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
    mergeSort(vec,0,vec.size());
    output(vec);
    return 0;
}
void mergeSort(vector<int>&vec,int starting,int ending){
    if(starting>=ending)    return;
    int mid=(starting+ending)/2;
    mergeSort(vec,starting,mid);
    mergeSort(vec,mid+1,ending);
    merge(vec,starting,mid,ending);
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}
void merge(vector<int>&vec,int starting,int mid,int ending){
    int an=(mid-starting+1),bn=ending-mid;
    vector<int>a(an);
    vector<int>b(bn);

    for(int i=0;i<an;i++)   a[i]=vec[i+starting];
    for(int j=0;j<bn;j++)   b[j]=vec[j+mid+1];

    int i=0,j=0,k=starting;
    while(i<an and j<bn){
        if(a[i]<b[j])   vec[k++]=a[i++];
        else    vec[k++]=b[j++];
    }
    while(i<an)     vec[k++]=a[i++];
    while(j<bn)     vec[k++]=b[j++];

    return;
}