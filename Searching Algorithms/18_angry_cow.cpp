/*WAP There is a new barn with N stalls and C rows.The stalls are located on a straight line
at positions x1,....,xN(0<=xi<=1,000,000,000).We want to assign the cows to the stalls,such
that the minimum distance between any two of them is as large as possible what is the largest
minimum distance??*/

#include<bits/stdc++.h>
using namespace std;
int largestMinimumDistance(vector<int>&distanceBetweenStalls,int cows);
bool cowsPlacement(vector<int>&distanceBetweenStalls,int mid,int cows);
int main()
{
    int stalls,cows,count=0;
    cout<<"Enter the number of stalls we have: ";
    cin>>stalls;cout<<endl;
    vector<int>distanceBetweenStalls(stalls);
    for(int &ele:distanceBetweenStalls){
        cout<<"Enter the "<<count++<<" distance: ";
        cin>>ele;
    }cout<<endl;
    cout<<"Enter the number of cows to be fiited in the stalls: ";
    cin>>cows;cout<<endl;
    int res=largestMinimumDistance(distanceBetweenStalls,cows);
    cout<<"The largest minimum distance between two cows is: "<<res;
    return 0;
}
int largestMinimumDistance(vector<int>&distanceBetweenStalls,int cows){
    int starting=1,ending=(distanceBetweenStalls[distanceBetweenStalls.size()-1]-distanceBetweenStalls[0]),ans=-1;
    while(starting<=ending){
        int mid=starting+(ending-starting)/2;
        if(cowsPlacement(distanceBetweenStalls,mid,cows)){
            ans=mid;
            starting=mid+1;
        }else   ending=mid-1;
    }
    return ans;
}
bool cowsPlacement(vector<int>&distanceBetweenStalls,int mid,int cows){
    int cowsReq=1,lastPosition=distanceBetweenStalls[0];
    for(int i=1;i<distanceBetweenStalls.size();i++){
        if(distanceBetweenStalls[i]-lastPosition>=mid){
            cowsReq++;
            lastPosition=distanceBetweenStalls[i];
            if(cowsReq==cows)    return true;
        }
    }
    return false;
}