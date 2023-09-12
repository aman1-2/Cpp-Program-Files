/*WAP A new racing track for kids is being built in New York with 'n' starting spots.The
spots are located along a straight line at position X1,X2.....,Xn(Xi<=10^9).For each 'i',
Xi+1>Xi.At a time only 'm' children are allowed to enter the race.Since the race track is
for kids,they may run into each other while running.To prevent this,we want to choose the
starting spots such that the minimum distance between any two of them is as large as 
possible.What is the largest minimum distance??

The first line of input will contain the value of n,the number of starting spots.
The second line of input will contain the n number denoting the location of each spot.
The third line will contain the value of m,number of childrens.

INPUT:-
5
1 2 4 8 9
3
OUTPUT:-
3*/

#include<bits/stdc++.h>
using namespace std;
int answerRangeBinarySearch(vector<int>&raceTrack,int stratingSpot);
bool childrenPlacement(vector<int>&raceTrack,int mid,int child);
int main(){
    int startingSpot,child,count=0;
    cout<<"Enter the total number of starting spots: ";
    cin>>startingSpot;
    vector<int>raceTrack(startingSpot);
    for(int &ele:raceTrack){
        cout<<"The "<<count++<<" strating spot is: ";
        cin>>ele;
    }cout<<endl;
    cout<<"Enter the number of children taken part in the race: ";
    cin>>child;
    int res=answerRangeBinarySearch(raceTrack,child);
    cout<<"The minimum distance between the two distance is the largest possible distance: "<<res;
    return 0;
}

/*This function is to find the largest possible distance which is the minimum distane from 
the group of arranging methods.*/
int answerRangeBinarySearch(vector<int>&raceTrack,int child){
    /*Defining the search space where we have to apply your binary search Now here interesting 
    thing to know about is the values of start and stop i.e the starting value will be 1 as
    the smallest possible distance that two cildren can have is 1.Whereas the ending value 
    will be (ending element-starting element) as the largest possible distance between two
    children can be if we place both the students at the terminals.
    Here we have too created an answer variable to store the best possible answer in it.*/
    int starting=1,ending=(raceTrack[raceTrack.size()-1]-raceTrack[0]),ans=-1;

    //Checking the condition if the strating value is less than or equal to ending value or not.
    while(starting<=ending){
        /*Calculating the mid value->Here mid value indicates that the distance between two
        children should always be more than or equal to mid value never less than it.*/
        int mid=starting+(ending-starting)/2;

        /*If we can place the children with mid value then we can easily place the children
        with less than mid value too*/
        if(childrenPlacement(raceTrack,mid,child)){
            ans=mid;
            //Therefore we have shifted our starting value to find out a better answer.
            starting=mid+1;
        }else   ending=mid-1;//On the other-hand if we aren't able to arrange it at the mid
        //value then we will reduce the search space and shift the ending value 

    }
    return ans;
}

/*This function is to check if we are able to place the children at the spots or not.
In this function we have passed three parameters and these are the spots(i.e vector)
the mid value(which is the minimum possible distance between the two children) and the last
is child(Number of children to place).*/
bool childrenPlacement(vector<int>&raceTrack,int mid,int child){
    /*We have placed our first student at the starting spot just why to leave the starting 
    spot.And too created a points Acquired variable that indicats that the points are occupied.*/
    int childReq=1,pointAcquired=raceTrack[0];

    /*Now going through each spots of the vector.*/
    for(int i=1;i<raceTrack.size();i++){
        /*Checking if the distance between the two children should be more than mid or equal
        to mid.And to claculate it is more than or equal to mid or not we have to just 
        subtract the current spot with the previous spot acquired.*/
        if(raceTrack[i]-pointAcquired>=mid){//If true then..
            childReq++;//Move to the next child
            pointAcquired=raceTrack[i];//Update the value of pointAcquired with current spot

            /*Give this check too that whether the childReq has reached the total children given
            or not if we have placed all the children then just return true.*/
            if(childReq==child) return true;
        }
        //We don't have to do anyting in else part.
    }
    //Whereas if it doesn't returns true than return the value false.
    return  false;
}