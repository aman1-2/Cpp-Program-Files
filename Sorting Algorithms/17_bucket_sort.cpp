#include<bits/stdc++.h>
using namespace std;
void bucketSort(vector<float>&vec);
void output(vector<float>&vec);
int main()
{
    int num,count=1;
    cout<<"Entre the number: ";
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
    //creation of bucket....
    vector<vector<float>>bucket(vec.size(),vector<float>());

    //finding the index of the element to place it in our bucket....
    for(int i=0;i<vec.size();i++){
        int index=(vec[i]*vec.size());
        bucket[index].push_back(vec[i]);
    }

    //Sorting each bucket....
    for(int i=0;i<vec.size();i++){
        sort(bucket[i].begin(),bucket[i].end());
    }

    //After sorting our each bucket placing the elements of each buckets into our oeiginal array....
    int idxSort=0; //maintaing an index for our sorted array....
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