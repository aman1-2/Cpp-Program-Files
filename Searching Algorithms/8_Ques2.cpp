/*WAP to find the square root of the given non-negative value x.Round it off to the nearest
floor integer value??...*/

#include<bits/stdc++.h>
using namespace std;
int squareRoot(int num);
int simpleSquareRoot(int num);
int main()
{
    int num;
    cout<<"Enter the number whose square root you want to find: ";
    cin>>num;
    if(num<0){
        cout<<"You have Passed a Negative number to find its square root this is not possible with this function.";
        return 0;
    }
    cout<<endl;
    int res=squareRoot(num);
    //int res=simpleSquareRoot(num);
    cout<<"Square Root of "<<num<<" is: "<<res;
    return 0;
}
int squareRoot(int num){
    /*Finding the Square Root While Finding the square root one thing that we know is that
    our square root will never go beyond the num passed and it will never become less than 1.
    
    Which states that we have a search space from 1 to num(where num is the number whose
    square root we have to find out) now here we have a search space from where we have to 
    simply found out the value of our square root.
    
    This type of binary search is basically known as Binary Search on answer
    
    rootof(num) -> [1,num] -> within the range find the biggest value whose square is less
    than or equal to num.*/
    
    int starting=1,ending=num,ans;
    while(starting<=ending){
        int mid=starting+(ending-starting)/2;

        if((mid*mid)<=num){
            ans=mid;
            starting=mid+1;
        }
        else    ending=mid-1;
    }
    return ans;

    /*Time complexity -> O(log n)
    Space complexity -> O(1)*/
}
int simpleSquareRoot(int num){
    /*Its is same only instead of binary approach we use linear approach over here*/
    int ans=-1;
    for(int i=1;i<num;i++){
        if((i*i)<=num)  ans=i;
        else    break;
    }
    return ans;

    /*Time complexity -> O(rootof(n)) n is num here.
    Space complexity -> O(1)*/
}