/*WAP Where You are given an array ‘pages’ of integer numbers. In this array, the ‘pages[i]’ 
represents the number of pages in the ‘i-th’ book. There are ‘m’ number of students, and the 
task is to allocate all the books to the students. 

Allocate books in a way such that:

Each student gets at least one book.
Each book should be allocated to a student.
Book allocation should be in a contiguous manner.
 
You have to allocate the books to ‘m’ students such that the maximum number of pages 
assigned to a student is minimum.*/

//Brute-Force apporach

#include<bits/stdc++.h>
using namespace std;
bool stuGettingBook(vector<int>&pages,int maxPages,int stu);
int main()
{
    int books,stu,count=1,ans=0,maxPages=0;
    cout<<"Enter the number of books provided: ";
    cin>>books;cout<<endl;
    vector<int>pages(books);
    for(int &ele:pages){
        cout<<"Give pages of "<<count++<<" book: ";
        cin>>ele;
    }cout<<endl;
    cout<<"Enter the number of students we have: ";
    cin>>stu;cout<<endl;

    if(stu>books){
        cout<<"It isn't possible to allocate all the students with books as the number of students available are more than the student we have!!";
        return 0;
    }

    for(int ele:pages)  maxPages+=ele;

    for(int i=1;i<=maxPages;i++){
        bool possible=stuGettingBook(pages,maxPages,stu);
        if(possible){
            ans=i;
            possible++;
        }
    }

    cout<<"The maximum number of pages a student will get wiil be: "<<ans;
    return 0;
}

bool stuGettingBook(vector<int>&pages,int maxPage,int stu){
    int stuReq=1,currentSum=0;

    for(int i=0;i<pages.size();i++){
        if(pages[i]>maxPage)    return false;
        if(pages[i]+currentSum>maxPage){
            currentSum=pages[i];
            stuReq++;
            if(stuReq>stu) return false;
        }else{
            currentSum+=pages[i];
        }
    }

    return true;
}