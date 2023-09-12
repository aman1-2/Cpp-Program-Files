#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int>&vec);
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
    insertionSort(vec);
    output(vec);
    return 0;
}
void insertionSort(vector<int>&vec){
    for(int i=1;i<vec.size();i++){
        int currentEle=vec[i],j=i-1;
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