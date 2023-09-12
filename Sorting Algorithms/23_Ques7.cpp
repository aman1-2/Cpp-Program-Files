/*WAP where you are given an array of positive and negative integers segregate them in linear
time and constant space.The output should print negtive numbers,followed by all positive
numbers??......*/

#include<bits/stdc++.h>
using namespace std;

void sorting(vector<int>&vec,int starting,int ending);
int partition(vector<int>&vec,int starting,int ending);
void output(vector<int>&vec);
void rotate(vector<int>&vec);

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
    sorting(vec,0,vec.size());
    rotate(vec);
    output(vec);
    return 0;
}
void sorting(vector<int>&vec,int starting,int ending){
    if(starting>=ending)    return;
    int pi=partition(vec,starting,ending);
    sorting(vec,starting,pi-1);
    sorting(vec,pi+1,ending);
    return;
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
void rotate(vector<int>&vec){
    int countNegative=0;
    for(int ele:vec)    if(ele<0)   countNegative++;

    for(int i=countNegative,j=vec.size()-1;i<j;)    swap(vec[i++],vec[j--]);

    for(int i=0,j=countNegative-1;i<j;) swap(vec[i++],vec[j--]);

    for(int i=0,j=vec.size()-1;i<j;)    swap(vec[i++],vec[j--]);

    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}

//SAME PIECE OF CODE FOR THE BELOW QUESTION TOO???...............

/*WAP where you are given an array of positive and negative integers segregate them in linear
time and constant space without changing their relative order of the vector.The output 
should print negtive numbers,followed by all positive numbers??......*/

