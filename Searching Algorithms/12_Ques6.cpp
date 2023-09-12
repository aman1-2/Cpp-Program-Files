/*WAP where you are given a search element in the rotated sorted array with duplicate elements.
Return true or 1 if the element is found otherwise return false (-1) or 0
INPUT:-Array={0,0,0,1,1,1,2,0,0,0}  Target=2
OUTPUT:- 1 (ture)......*/

#include<bits/stdc++.h>
using namespace std;
bool searching(vector<int>&vec,int search);
void rotation(vector<int>&vec,int times);
void reversal(vector<int>&vec,int starting,int ending);
void output(vector<int>&vec);
int main()
{
    int num,count=0,search,times;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    cout<<endl;
    cout<<"Enter the number which you want to check is present in the array or not: ";
    cin>>search;
    cout<<endl;
    cout<<"Enter the number of times you want to rotate the array: ";
    cin>>times;
    cout<<endl;
    output(vec);
    cout<<endl;
    rotation(vec,times);
    output(vec);
    cout<<endl;
    bool res=searching(vec,search);
    if(res==true)  cout<<"The element you are searching is present in the array.";
    else    cout<<"The element you are searching isn't present in the array.";
    return 0;
}

bool searching(vector<int>&vec,int search){
    int starting=0,ending=vec.size()-1;

    /*Here we are firstly ensuring wheteher our search elements are corner or terminal 
    elements or not if yes then just return true that we have found the element.*/
    if(vec[starting]==search or vec[ending]==search)    return true; 

    /*If not and checking if the terminals are equal in that case just try to making the
    terminal(corner) elements distinct by moving the starting and ending pointers of the 
    array in other words we are just trying to remove those repetative elements.*/
    while(vec[starting]==vec[ending]){
        starting++,ending--;
    }

    /*Now after removing the starting repeated terminal elements we are just left with 
    maybe a sorted rotated or just sorted array where we can apply the binary search of 
    sorted rotated one case.*/
    if(vec[starting]>vec[ending]){
        while(starting<=ending){
            int mid=starting+(ending-starting)/2;
            if(vec[mid]==search)    return true;
            if(vec[mid]>=vec[starting]){
                if(search<=vec[mid] and search>=vec[starting])    ending=mid-1;
                else    starting=mid+1;
            }else{
                if(search<=vec[ending] and search>=vec[mid])  starting=mid+1;
                else    ending=mid-1;
            }
        }
    }else{
        while(starting<=ending){
            int mid=starting+(ending-starting)/2;
            if(vec[mid]==search)    return true;
            if(vec[mid]>search) ending=mid-1;
            else    starting=mid+1;
        }
    }

    /*At the end after cheking all the condition and loop holes if we still don't found our 
    element in that case element isn't present in the array in such case just return flase.*/
    return false;
}

void rotation(vector<int>&vec,int times){
    if(times>vec.size())    times=times%vec.size();

    reversal(vec,0,vec.size());
    reversal(vec,0,times);
    reversal(vec,times,vec.size());

    return;
}

void reversal(vector<int>&vec,int strating,int ending){
    for(int i=strating,j=ending;i<j;i++,j--)    swap(vec[i],vec[j]);
    return;
}

void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}