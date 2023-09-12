/*WAP where you are given a sorted rotated array of integers,which contains distinct elements 
and an integer target.Return the index of target if it is in the array otherwise return -1.
INPUT:- Array={3,4,5,1,2}  Target=4
OUTPUT:- 1*/

#include<bits/stdc++.h>
using namespace std;
void quickSort(vector<int>&vec,int starting,int ending);
int partition(vector<int>&vec,int starting,int ending);
void rotation(vector<int>&vec,int times);
void reversal(vector<int>&vec,int starting,int ending);
int searching(vector<int>&vec,int search);
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

    quickSort(vec,0,vec.size());
    output(vec);
    cout<<endl;

    cout<<"Enter the element you want to search: ";
    cin>>search;
    cout<<endl;

    cout<<"Enter the number of times you want to rotate: ";
    cin>>times;
    cout<<endl;

    rotation(vec,times);
    output(vec);
    cout<<endl;

    int res=searching(vec,search);
    cout<<endl;
    if(res==-1) cout<<"The element you are searching isn't present in the vector.";
    else    cout<<"The index where "<<search<<" is present is: "<<res;

    return 0;
}

void reversal(vector<int>&vec,int starting,int ending){
    for(int i=starting,j=ending;i<j;i++,j--)    swap(vec[i],vec[j]);
}

void rotation(vector<int>&vec,int times){
    if(times>vec.size())    times=times%vec.size();

    reversal(vec,0,vec.size());
    reversal(vec,0,times);
    reversal(vec,times,vec.size());

    return;
}

void quickSort(vector<int>&vec,int starting,int ending){
    if(starting>=ending)    return;

    int pi=partition(vec,starting,ending);

    quickSort(vec,starting,pi-1);
    quickSort(vec,pi+1,ending);

}
//{3,5,4,1,2,}
int partition(vector<int>&vec,int starting,int ending){
    int pivot=vec[ending];

    int i=starting-1;

    for(int j=starting;j<ending;j++){
        if(vec[j]<pivot){
            i++;
            swap(vec[i],vec[j]);
        }
    }

    swap(vec[i+1],vec[ending]);

    return i+1;
}


int searching(vector<int>&vec,int search){
    int starting=0,ending=vec.size()-1;

    if(vec[starting]>vec[ending]){//Here we are checking whether it is sorted rotated array or not
        while(starting<=ending){//Applying binary search
            int mid=starting+(ending-starting)/2;//Finding mid element

            if(vec[mid]==search)    return mid;//If search is equal to mid return mid

            /*Now we can distinguish our array as two part one which has sorted element in
            it and the other which has some sorted and some unsorted elements in it.*/
            if(vec[mid]>=vec[starting]){//if mid is more than starting(falls in rotated part)
                /*If the search is less than mid and greater than starting then the search 
                element falls within the rotated part then we have change our ending position
                If not valid then change the starting position.*/
                if(search<=vec[mid] and search>=vec[starting])  ending=mid-1;
                else    starting=mid+1;
            }else{
                /*Whereas if the mid element is less than the starting element in that case we
                will fall in the unsorted portion category
                Where if the search element is more than our mid element and less than our ending
                this indicate that we are falling in the sorted part of the non-rotated portion
                if this condition comes out to be valid then change the starting position
                else change the ending position*/
                if(search>=vec[mid] and search<=vec[ending])    starting=mid+1;
                else    ending=mid-1;
            }

        }
    }else{/*Whereas if we have recieved a sorted array after rotation or if there is no
    rotation in that case we have to apply the simple binary search*/
        while(starting<=ending){
            int mid=starting+(ending-starting)/2;

            if(vec[mid]==search)    return mid;

            if(vec[mid]>search) ending=mid-1;
            else    starting=mid+1;

        }
    }

    /*If we are done with all our brains and yet not found the element in that case you are
    fooled and the element isn't present in the array and in such situation just return -1.*/
    return -1;
}

void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}