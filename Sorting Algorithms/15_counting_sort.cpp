#include<bits/stdc++.h>
using namespace std;
void countingSort(vector<int>&vec);
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
    countingSort(vec);
    output(vec);
    return 0;
}
void countingSort(vector<int>&vec){
    int maxEle=vec[0];
    for(int ele:vec)    maxEle=max(ele,maxEle);

    vector<int>freq(maxEle+1,0);
    for(int i=0;i<vec.size();i++)   freq[vec[i]]++;

    for(int i=1;i<maxEle+1;i++)     freq[i]+=freq[i-1];

    vector<int>ans(vec.size());
    for(int i=vec.size()-1;i>=0;i--)      ans[--freq[vec[i]]]=vec[i];

    for(int i=0;i<vec.size();i++)       vec[i]=ans[i];
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}