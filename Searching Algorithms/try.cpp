#include<bits/stdc++.h>
using namespace std;
int searching(vector<int>&vec,int search);
int main(){
    int num,count=0,search; 
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" ele: ";
        cin>>ele;
    }
    cout<<"Enter the element you want to search from array/vector: ";
    cin>>search;
    int res=searching(vec,search);
    if(res!=-1) cout<<"The index of the element you are searching in the array/vector: "<<res;
    else    cout<<"The element you are searching isn't present in the vector/array.";
    return 0;
}
int searching(vector<int>&vec,int search){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==search)  return i ;
    }
    return -1;
}