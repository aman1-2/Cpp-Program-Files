/*WAP To search the 'target' value in a 2-D integer matrix of dimensions nxm and return 1.
If found,else return 0.This matrix has the following properties:-
(i)Integers in each row are sorted from left to right.
(ii)The first integer of each row is greater than the last integer of the previous row.

INPUT:- Matrix=[[1,3,5,7],[10,11,16,20],[23,30,34,60]]
        Target=3
Output:- 1(True).. */

#include<bits/stdc++.h>
using namespace std;
bool searching(vector<vector<int>>&vec,int search);
int main()
{
    int rows,columns,count=0,search;
    cout<<"Enter the Rows: ";
    cin>>rows;
    cout<<"Enter the Columns: ";
    cin>>columns;
    vector<vector<int>>vec(rows,vector<int>(columns,0));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            int ele;
            cout<<"Enter the "<<count++<<" element: ";
            cin>>ele;
            vec[i][j]=ele;
        }
    }
    cout<<endl;
    cout<<"Enter the number which you want to search: ";
    cin>>search;
    int res=searching(vec,search);
    if(res==1)  cout<<"True";
    else    cout<<"False";
    return 0;
}
bool searching(vector<vector<int>>&vec,int search){
    /*Defining the search space from start till the end of our 2d vector/array.*/
    int starting=0,ending=vec.size()*vec[0].size()-1;

    //Checking a condition if our starting value is less than or equal to the ending then only run the loop.
    while(starting<=ending){

        //Finding the mid value.
        int mid=starting+(ending-starting)/2;

        /*Here calculating the co-ordinate of our mid value to find out the exact loction of
        the mid value in our 2d vector/array.*/
        int x=mid/vec[0].size(),y=mid%vec[0].size();

        /*If the mid value i.e the actual x and y co-ordinate pointing to any value in the 
        2d vector/array is equal to the search element in that case simple return true.*/
        if(vec[x][y]==search)   return true;
        else if(vec[x][y]<search)   starting=mid+1;//Whereas if the mid (Co-ordinates) are less than search shift starting.
        else    ending=mid-1;//Otherwise shift ending.
    }
    return false;
}