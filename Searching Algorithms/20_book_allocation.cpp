/*WAP Where You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ 
represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the 
task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages 
assigned to a student is minimum.*/

#include<bits/stdc++.h>
using namespace std;
int bookAllocation(vector<int>&pages,int stu);
bool stuGettingBook(vector<int>&pages,int mid,int stu);
int main()
{
    int books,stu,count=1;
    cout<<"Enter the number of books: ";
    cin>>books;
    vector<int>pages(books);
    for(int &ele:pages){
        cout<<"Give pages of "<<count++<<" book: ";
        cin>>ele;
    }cout<<endl;
    cout<<"Enter the number of student: ";
    cin>>stu;cout<<endl;
    if(stu>books)   cout<<"The number of students available are more than books we have.\nHence we cann't allocate each student with a book!!";
    else{
        int res=bookAllocation(pages,stu);
        cout<<"The maximum pages a student gets wiil be: "<<res;
    }
    return 0;
}
int bookAllocation(vector<int>&pages,int stu){
    int starting=pages[0],ending=0,ans=-1;

    for(int i=0;i<pages.size();i++) ending+=pages[i];

    while(starting<=ending){
        int mid=starting+(ending-starting)/2;
        if(stuGettingBook(pages,mid,stu)){
            ans=mid;
            ending=mid-1;
        }else   starting=mid+1;
    }

    return ans;
}
bool stuGettingBook(vector<int>&pages,int mid,int stu){
    int stuReq=1,currentSum=0;

    for(int i=0;i<pages.size();i++){
        if(pages[i]>mid)    return false;
        if(pages[i]+currentSum>mid){
            currentSum=pages[i];
            stuReq++;
            if(stuReq>stu) return false;
        }else{
            currentSum+=pages[i];
        }
    }

    return true;
}