/*WAP where you are given an array where all its elements are sorted in increasing order 
except two swapped elements,sort it in linear time.Assume there are no duplicates in the
array??......*/
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
            if(vec[i]==vec[j]){
                flag=true;
                cout<<"!!ERROR!!\nYou cann't have two repetative elements in the vector....";
                break;
            }
        }
    }

    if(!flag){
        sorting(vec);
        output(vec);
    }
    return 0;
}
void sorting(vector<int>&vec){
    for(int i=1;i<vec.size();i++){
        int j=i-1,currentEle=vec[i];
        while(j>=0 and vec[j]>currentEle){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=currentEle;
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}