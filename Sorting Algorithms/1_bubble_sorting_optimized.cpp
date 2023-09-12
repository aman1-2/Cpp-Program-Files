#include<bits/stdc++.h>
using namespace std;
void optimizedWhile(vector<int>&vec);
void optimizedFor(vector<int>&vec);
void output(vector<int>&vec);
int main()
{
    int num,count=1;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" number: ";
        cin>>ele;
    }
    cout<<"With the help of the while loop:-"<<endl;
    optimizedWhile(vec);
    output(vec);
    cout<<endl;
    cout<<"With the help of the for loop:-"<<endl;
    optimizedFor(vec);
    output(vec);
    return 0;
}
void optimizedWhile(vector<int>&vec){
    int i=0,count=0;
    while(i<vec.size()-1){
        bool flag=false;
        for(int j=0;j<(vec.size()-1)-i;j++){
            if(vec[j]>vec[j+1]){
                flag=true;
                swap(vec[j],vec[j+1]);
            }
        }
        if(!flag)   break;
        i++;
    }
    return;
}
void optimizedFor(vector<int>&vec){
    int count=0;
    for(int i=0;i<vec.size()-1;i++){
        bool flag=false;
        for(int j=0;j<(vec.size()-1)-i;j++){
            if(vec[j]>vec[j+1]){
                flag=true;
                swap(vec[j],vec[j+1]);
            }
        }
        if(!flag)   break;
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}