#include<bits/stdc++.h>
using namespace std;
void bubbleSorting(vector<int>&vec);
void bubbleSortingWhile(vector<int>&vec);
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
    bubbleSortingWhile(vec);
    output(vec);
    return 0;
}
void bubbleSorting(vector<int>&vec){
    int i=0;
    while(i<vec.size()-1){
        for(int j=0;j<(vec.size()-1)-i;j++){
            if(vec[j]>vec[j+1])     swap(vec[j],vec[j+1]);
        }
        i++;
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}
void bubbleSortingWhile(vector<int>&vec){
    cout<<"Fully-While:-"<<endl;
    int i=0;
    while(i<vec.size()-1){
        int j=0;
        while(j<(vec.size()-1)-i){
            if(vec[j]>vec[j+1])     swap(vec[j],vec[j+1]);
            j++;
        }
        i++;
    }
    return;
}