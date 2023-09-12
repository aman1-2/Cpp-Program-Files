/*WAP There is a new barn with N stalls and C rows.The stalls are located on a straight line
at positions x1,....,xN(0<=xi<=1,000,000,000).We want to assign the cows to the stalls,such
that the minimum distance between any two of them is as large as possible what is the largest
minimum distance??*/

//Brute-force solution:-

#include<bits/stdc++.h>
using namespace std;
bool cowsPlacement(vector<int>&distanceBetweenStalls,int cows,int distance);
int main(){
    /*Taken the value of how many stalls are present in a line and how many cows we have to
    place in these stalls.
    we too have an ans variable to store the best possible answer in it.*/
    int stalls,cows,count=0,ans;
    cout<<"Enter the number of stalls provided: ";
    cin>>stalls;cout<<endl;

    /*Here we have a vector which stores the distance between the two stalls*/
    vector<int>distanceBetweenStall(stalls);
    for(int &ele:distanceBetweenStall){
        cout<<"Enter the "<<count++<<" distance: ";
        cin>>ele;
    }cout<<endl;

    cout<<"Enter the number of cows to be placed: ";
    cin>>cows;

    /*We have calculated the maximum distance between two cows colud be
    (last stall position - the first stall position) and this is the distance to be placed if we
    we have two cows they can be placed at two different positions.*/
    int maxDist=(distanceBetweenStall[distanceBetweenStall.size()-1]-distanceBetweenStall[0]);

    /*Since we know the maximum distance between any two cows could be maxDist this shows that
    our answer will be between 1 to maxDist [Why 1? 1 is the minimum or the smallest possible
    distance between at two cows] there for we will go at every possible distance form 1 to 
    maxDist to find out our best possible answer.*/
    for(int distance=1;distance<=maxDist;distance++){
        /*Here we have used a cowsPlacement Function to place the cows if we are able to place
        all the cows at distance value then we will store it ans variable otherwise move on to 
        our next distance value.*/
        bool possible=cowsPlacement(distanceBetweenStall,cows,distance);

        if(possible){//If the value of possible is true
            ans=distance;//Modify the ans variable
        }
        //And if its false just move onto the next distance value
    }

    //At the end just print the ans variable.
    cout<<"The largest minimum distance between two cows is: "<<ans;
    return 0;
}

/*This Function is to check if the cows can be placed at diffrent distance ranging between
1 to maxDist(which is last stall position - first stall position)
In this we will try to place the cows at stalls with the minimum possible distance betweem
them as distance if we will be able to place all of them then return true otherwise a false.*/
bool cowsPlacement(vector<int>&distanceBetweenStalls,int cows,int distance){

    /*The lastPosition at which the cow has ocuppied the stall.So this we have started with
    the first position only why to start form any other point.
    Then we have a cowsReq variable too that shows the cows placed.*/
    int lastPosition=distanceBetweenStalls[0],cowsReq=1;

    /*We are running a loop to place the cows with the number of stalls present for us.*/
    for(int i=1;i<distanceBetweenStalls.size();i++){

        /*If the distance between the two stalls or two cows placed is more than or equal
        to distance then place the cow.
        The distance between the cows colud be found by subtracting the current position to
        the last occupied position of the cow.*/
        if(distanceBetweenStalls[i]-lastPosition>=distance){
            //If true increment the cowsReq value
            cowsReq++;

            //If true then update the lastPosition of the cow in the stall with current
            //position.
            lastPosition=distanceBetweenStalls[i];

            /*As soon as possibe the value of cowsReq is reached the cows provided just
            return true and end the program*/
            if(cowsReq==cows)   return true;
        }
    }
    /*If we haven't returned true above then return false.*/
    return false;
}