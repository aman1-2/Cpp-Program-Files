/*WAP to find the kth position element in an array using quicksort???*/
#include<bits/stdc++.h>
using namespace std;
int kthElement(vector<int>&vec,int starting,int ending,int eleSearch);
int partition(vector<int>&vec,int starting,int ending);
int main()
{
    int num,count=1,eleIdxKnow;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<"Enter the position whose correct value you want to find from your sorted array: ";
    cin>>eleIdxKnow;
    int kthEle=kthElement(vec,0,vec.size(),eleIdxKnow);
    if(kthEle!=-1)     cout<<"The element present at the kth position is "<<kthEle;
    else    cout<<"This index or position i.e the number you have given is wrong as our array dosn't have these many elements..ERROR!!!!";
    return 0;
}
int kthElement(vector<int>&vec,int starting,int ending,int eleIdxKnow){
    if(eleIdxKnow>0 and eleIdxKnow<=ending-starting+1){
        int position=partition(vec,starting,ending);
        if(position-starting==eleIdxKnow-1)    return vec[position];
        else if(position-starting>eleIdxKnow-1)  return kthElement(vec,starting,position-1,eleIdxKnow);
        else if(position-starting<eleIdxKnow-1)  return kthElement(vec,position+1,ending,eleIdxKnow-(position-starting+1));
    }
    return -1;
}
int partition(vector<int>&vec,int starting,int ending){
    int pivot=vec[ending];
    int i=starting-1;
    for(int j=starting;j<ending;j++){
        if(vec[j]<pivot){
            i++;
            swap(vec[j],vec[i]);
        }
    }
    swap(vec[i+1],vec[ending]);
    return i+1;
}