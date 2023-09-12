/*WAP where you are given an array of names of the fruits;You are supposed to sort it
in lexicographical order using the selection sort??......
INPUT:- ["papaya","lime","watermelon","apple","mango","kiwi"]
OUTPUT:-["apple","kiwi","lime","mango","papaya","watermelon"]......*/
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void sorting(char arr[][60]);
void output(char arr[][60]);
int main()
{
    char arr[][60]={"papaya","lime","watermelon","apple","mango","kiwi"};
    sorting(arr);
    output(arr);
    return 0;
}
void sorting(char arr[][60]){
    for(int i=0;i<6-1;i++){
        int minIdx=i;
        for(int j=i+1;j<6;j++){
            if(strcmp(arr[minIdx],arr[j])>0){
                minIdx=j;
            }
        }
        if(i!=minIdx)   swap(arr[i],arr[minIdx]);
    }
    return;
}
void output(char arr[][60]){
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    return;
}