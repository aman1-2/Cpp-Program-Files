/*WAP to find the occurrence of a given element x,given that the given array is sorted.
if no occurrence of x is found then return -1???......
INPUT:- {2,5,5,5,6,6,8,9,9,9} 
x=5
OUTPUT:- 1......*/

#include<bits/stdc++.h>
using namespace std;
void sorting(vector<int>&vec); //Sorting Function
int searching(vector<int>&vec,int search); //Searching Function
int main()
{
    int num,count=0,search;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    sorting(vec); //Sortef the array before starting our search.
    cout<<endl;
    cout<<"Enter the number which you want to search in the vector: ";
    cin>>search;
    int res=searching(vec,search);
    cout<<res;
    return 0;
}
void sorting(vector<int>&vec){
    int maxEle=INT_MIN;
    for(int ele:vec)    maxEle=max(ele,maxEle);

    vector<int>freq(maxEle+1,0);
    for(int i=0;i<vec.size();i++)   freq[vec[i]]++;
    for(int i=1;i<=maxEle;i++)  freq[i]+=freq[i-1];

    vector<int>ans(vec.size());
    for(int i=vec.size()-1;i>=0;i--)    ans[--freq[vec[i]]]=vec[i];

    for(int i=0;i<vec.size();i++)   vec[i]=ans[i];

    return;
}

int searching(vector<int>&vec,int search){
    /*Created an extra ans variable to store the returned index (i.e mid value) when we have 
    found our element this is because this time we don't have to find the element we have to
    find its first occurence.Therefore the found element may or may not be the first 
    occurence.
    And if the found element isn't the first occurence then the first occurence of that element
    will come before our found element in that case we just store the current index of found
    element in our index and then move on to search more least index of the found element.
    if the better ans is found ans variabe is then just upadated.*/
    int starting=0,ending=vec.size()-1,ans=-1;
    /*We have just initialized our ans variable with -1 in case our search element is not
    present in the data then we just have to return -1.*/

    while(starting<=ending){
        int mid=starting+(ending-starting)/2;

        if(vec[mid]==search){
            ans=mid;//Storing the index of current found element.
            ending=mid-1;//Then reducing the search space for better answer.
        }
        else if(vec[mid]<search)    starting=mid+1;
        else    ending=mid-1;
    }
    return ans;//The ans variable as answer.
}