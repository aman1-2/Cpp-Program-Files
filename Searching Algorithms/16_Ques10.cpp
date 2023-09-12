//This binary search is over the answer range


/*WAP You have 'n'(n<=10^5)boxes of chocolate.Each box contain a[i](a[i]<=10000)
chocolates.You need to distribute these boxes among 'm' students such that the maximum number
of chocolates allocated to a student is minimum.
(a)One box will be allocated to exactly one student.
(b)All the boxes should be allocated.
(c)Each student has to be allocated atleast one box.
(d)Allotment should be in contiguous order,for instance,a student cannot be allocated box 1
and then box 3,skipping box 2.

Calculate and return that minimum possile number.
Assume that it is always possible to distribute the chocolates.
Assuming that the chocolates given are sorted in increasing order.

The first line of input will contain the value of n,the number of boxes.
The second line of input will contain the n numbers denoting the number of chocolates in each
box.
The third line will contain the m,Number of students.

INPUT:-  4
        12 34 67 90
        2
OUTPUT:- 113 */


#include<bits/stdc++.h>
using namespace std;
int chocolateEachStudentGet(vector<int>&vec,int stu);
bool chocolateDistribution(vector<int>&vec,int mid,int stu);
int main()
{
    int boxes,stu,count=0;
    cout<<"Enter the number of boxes: ";
    cin>>boxes;cout<<endl;
    vector<int>vec(boxes);
    for(int &ele:vec){
        cout<<"Enter the chocolate in "<<count++<<" box: ";
        cin>>ele;
    }cout<<endl;
    cout<<"Enter the number of students present: ";
    cin>>stu;cout<<endl;
    int res=chocolateEachStudentGet(vec,stu);cout<<endl;
    cout<<"The Maximum chocolate got by one student is: "<<res;cout<<endl;
    return 0;
}

int chocolateEachStudentGet(vector<int>&vec,int stu){

    /*Defining the search space for searching the answer.
    Where the starting point of the search space is from the starting value of the vector/
    array group which represents choocolates present in each box.
    Whereas the ending is the total sum of chocolates present in each box.
    We too have creeated a ans variable to store the answer in it.*/
    int starting=vec[0],ending=0,ans=-1;//12->203
    //Finding the ending point.
    for(int ele:vec)    ending+=ele;

    while(starting<=ending){
        //calculating the mid value.
        int mid=starting+(ending-starting)/2;

        /*Now checking a condition if the the chocolates are properly distributed with mid
        value as the maximum chocolates to be given then mid can be our answer but there are
        chances of finding a better answer.
        
        TO check the correct chocolate distribution we have creared a function for it too
        
        If the answer is true store the value of mid in answer otherwise shift ending 
        position.
        
        whereas if its false then in that case simply shift the starting value.*/
        if(chocolateDistribution(vec,mid,stu)){
            ans=mid;
            ending=mid-1;
        }else   starting=mid+1;
    }
    
    /*At the end simply return the ans variable*/
    return ans;
}

//Chocolate Distribution among the student.
bool chocolateDistribution(vector<int>&vec,int mid,int stu){
    /*Now the constrain over here are that there should be atleast one student 
    and currentSum variable to store the chocolates sum.*/
    int studentRequired=1,currentSum=0;

    /*Going through each box to get distributed*/
    for(int i=0;i<vec.size();i++){
        /*If in any of the box the value of chocolate goes above the mid then simply return
        false in that case.*/
        if(vec[i]>mid)  return false;
        if(currentSum+vec[i]>mid){/*Now the next condition is if in any case if the sum
        of chocaltes in two or more boxes goes above mid then switch the child(increment the
        value of studentRequired)*/
            studentRequired++;
            currentSum=vec[i];

            /*Wheres if the value of studentRequired only goes above the student provided
            in that case too you have to return the vlaue as flase only.As there won't be any
            student left to distribute the chocolate boxes.*/
            if(studentRequired>stu) return false;

        }else{/*And if none of these conditon hit then simply go on adding the each gone chocolate
        boxes.*/
            currentSum+=vec[i];
        }
    }

    /*If all this goes well then return the value true.*/
    return true;
}