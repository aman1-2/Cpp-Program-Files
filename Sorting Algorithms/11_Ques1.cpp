/*WAP where you are given an integer of array arr, move all 0's to the end of it while
maintaining the relative order of the non-zero elements??......
NOTE:-   0 5 0 3 4 2
OUTOUT:- 5 3 4 2 0 0......*/

#include<bits/stdc++.h>
using namespace std;
void placingZero(vector<int>&vec);
void output(vector<int>&vec);
void method2(vector<int>&vec);
void method3(vector<int>&vec);
int main()
{
    int num,count=1;
    cout<<"Enter the number: ";
    cin>>num;
    vector<int>vec(num);
    for(int &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    placingZero(vec);
    output(vec);
    cout<<endl;
    method2(vec);
    output(vec);
    cout<<endl;
    method3(vec);
    output(vec);
    return 0;
}
void placingZero(vector<int>&vec){
    for(int i=vec.size()-2;i>=0;i--){
        int currentEle=vec[i],j=i+1;
        if(currentEle!=0)   continue;
        else{
            while(j<=vec.size()-1){
                vec[j-1]=vec[j];
                j++;
            }
            vec[j-1]=currentEle;
        }
    }
    return;
}
void output(vector<int>&vec){
    for(int ele:vec)    cout<<ele<<" ";
    return;
}
void method2(vector<int>&vec){
    cout<<"Second Method:-"<<endl;
    int countZero=0;
    for(int i=0;i<vec.size();i++){
        if(i==0)    countZero++;
    }

    for(int i=vec.size()-countZero;i>=0;i--){
        int currentEle=vec[i],j=i+1;
        if(currentEle!=0)   continue;
        else{
            while(j<=vec.size()-1){
            vec[j-1]=vec[j];
            j++;
            }
            vec[j-1]=currentEle;
        }
    }
    return;
}
void method3(vector<int>&vec){
    cout<<"Third Method:-"<<endl;
    for(int i=vec.size()-1;i>=0;i--){
        int j=0;
        bool flag=false;
        while(j!=0){
            if(vec[j]==0 and vec[j+1]!=0){
                swap(vec[j],vec[j+1]);
                flag=true;
            }
            j++;
        }
        if(!flag)   break;
    }
    return;
}