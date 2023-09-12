#include<bits/stdc++.h>
using namespace std;
void radixSort(vector<int>&vec);
void countingSort(vector<int>&vec,int position);
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
    radixSort(vec);
    output(vec);
    return 0;
}
void radixSort(vector<int>&vec){
    int maxEle=INT_MIN;
    for(int ele:vec)    maxEle=max(ele,maxEle);

    for(int position=1;(maxEle/position)>0;position*=10)    countingSort(vec,position);
    return;
}
void countingSort(vector<int>&vec,int position){
    vector<int>freq(10,0);

    for(int i=0;i<vec.size();i++)   freq[(vec[i]/position)%10]++;
    for(int i=1;i<10;i++)   freq[i]+=freq[i-1];

    vector<int>ans(vec.size());
    for(int i=vec.size()-1;i>=0;i--)    ans[--freq[(vec[i]/position)%10]]=vec[i];

    for(int i=0;i<vec.size();i++)   vec[i]=ans[i];

    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}