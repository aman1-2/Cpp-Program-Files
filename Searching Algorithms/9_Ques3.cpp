/*WAP where you are given an array of integer's 'a' that is sorted in non-decreasing order.
Find the first and the last position of the given 'target' element in the sorted array.
Follow 0-based indexing.
If 'target' is not found in the array return [-1,-1].

INPUT:- Array={1,2,3,3,3,5,11}  Target=3
OUTPUT:- [2,4].*/

#include<bits/stdc++.h>
using namespace std;
int firstPosition(vector<int>&vec,int search);
int lastPosition(vector<int>&vec,int search);
int main(){
    int num,count=0,search;
    cout<<"Enter the number: ";
    cin>>num;

    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<endl;

    cout<<"Enter the element whose First and Last index you want to know: ";
    cin>>search;

    pair<int,int>p;

    int firstPos=firstPosition(vec,search);

    if(firstPos==-1){
        p=make_pair(-1,-1);
    }
    else{
        int lastPos=lastPosition(vec,search);
        p=make_pair(firstPos,lastPos);
    }

    cout<<endl;
    cout<<"Pair of the first and last position of the searched element "<<search<<" is: ("<<p.first<<","<<p.second<<")";
    return 0;
}


int firstPosition(vector<int>&vec,int search){
    int starting=0,ending=vec.size()-1,firstPos=-1;

    while(starting<=ending){
        int mid=starting+(ending-starting)/2;

        if(vec[mid]==search){
            firstPos=mid;
            ending=mid-1;
        }
        else if(vec[mid]<search)    starting=mid+1;
        else    ending=mid-1;
    }

    return firstPos;
}


int lastPosition(vector<int>&vec,int search){
    int starting=0,ending=vec.size()-1,lastPos=-1;

    while(starting<=ending){
        int mid=starting+(ending-starting)/2;

        if(vec[mid]==search){
            lastPos=mid;
            starting=mid+1;
        }
        else if(vec[mid]<search)    starting=mid+1;
        else    ending=mid-1;
    }

    return lastPos;
}

/*Trying to get the first and last poition separately and then clubing their answers
in the pair STL function to get our answer.
Now we have performed the same algorithm which we performed to find the first occurence of
the element to find out first and last index separately.*/