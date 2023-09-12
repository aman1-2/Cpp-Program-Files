#include<bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&vec);
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
    selectionSort(vec);
    output(vec);
    return 0;
}
void selectionSort(vector<int>&vec){
    for(int i=0;i<vec.size()-1;i++){
        int minIdx=i;
        for(int j=i+1;j<vec.size();j++){
            if(vec[j]<vec[minIdx])  minIdx=j;
        }
        if(minIdx!=i)   swap(vec[i],vec[minIdx]);
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}