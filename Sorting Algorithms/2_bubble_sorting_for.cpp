#include<bits/stdc++.h>
using namespace std;
void bubbleSorting(vector<int>&vec);
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
    bubbleSorting(vec);
    output(vec);
    return 0;
}
void bubbleSorting(vector<int>&vec){
    for(int i=0;i<vec.size()-1;i++){
        for(int j=0;j<(vec.size()-1)-i;j++){
            if(vec[j]>vec[j+1])     swap(vec[j],vec[j+1]);
        }
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}