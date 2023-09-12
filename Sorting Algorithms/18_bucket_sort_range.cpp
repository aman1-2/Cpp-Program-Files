#include<bits/stdc++.h>
using namespace std;
void bucketSort(vector<float>&vec);
void output(vector<float>&vec);
int main()
{
    int num,count=1;
    cout<<"Enter the number: ";
    cin>>num;
    vector<float>vec(num);
    for(float &ele:vec){
        cout<<"Enter the "<<count++<<" element: ";
        cin>>ele;
    }
    bucketSort(vec);
    output(vec);
    return 0;
}
void bucketSort(vector<float>&vec){
    vector<vector<float>>bucket(vec.size(),vector<float>());
    int maxEle=INT_MIN,minEle=INT_MAX;
    for(int ele:vec){
        maxEle=max(ele,maxEle);
        minEle=min(ele,minEle);
    }

    int range=(maxEle-minEle)/vec.size();

    for(int i=0;i<vec.size();i++){
        int index=(vec[i]-minEle)/range;
        int diff=((vec[i]-minEle)/range)-index;
        if(diff==0 and vec[i]!=minEle)  bucket[index-1].push_back(vec[i]);
        else    bucket[index].push_back(vec[i]);
    }

    for(int i=0;i<vec.size();i++){
        if(!bucket[i].empty())  sort(bucket[i].begin(),bucket[i].end());
    }

    int idxSort=0;
    for(int i=0;i<bucket.size();i++){
        for(int j=0;j<bucket[i].size();j++){
            vec[idxSort++]=bucket[i][j];
        }
    }

    return;
}
void output(vector<float>&vec){
    for(float ele:vec)    cout<<ele<<" ";
    return;
}