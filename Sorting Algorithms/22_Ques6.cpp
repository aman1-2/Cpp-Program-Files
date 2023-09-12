/*WAP where you are given an array of size n containing only 0's ,1's and 2's sort the
array in ascending order??......*/
#include<bits/stdc++.h>
using namespace std;
void sorting(vector<int>&vec);
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

    bool flag=false;
    for(int i=0;i<vec.size();i++){
        int currentEle=vec[i];
        for(int j=i+1;j<vec.size();j++){
            if(vec[i]==0 or vec[i]==1 or vec[i]==2)     continue;
            else{
                flag=true;
                cout<<"!!ERROR!!\nYou cann't have two repetative elements in the vector....";
                break;
            }
        }
        if(flag)    break;
    }

    if(!flag){
        sorting(vec);
        output(vec);
    }
    return 0;
}
void sorting(vector<int>&vec){
    int maxEle=INT_MIN;
    for(int ele:vec)    maxEle=max(ele,maxEle);

    vector<int>freq(maxEle+1,0);
    for(int i=0;i<vec.size();i++)   freq[vec[i]]++;

    for(int i=1;i<maxEle+1;i++)   freq[i]+=freq[i-1];

    vector<int>ans(vec.size());
    for(int i=vec.size()-1;i>=0;i--)    ans[--freq[vec[i]]]=vec[i];

    for(int i=0;i<vec.size();i++)   vec[i]=ans[i];

    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}