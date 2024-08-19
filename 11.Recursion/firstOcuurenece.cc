#include<iostream>
#include<vector>
using namespace std;
int fo(vector <int> arr,int i,int target){
    if(arr[i]==target){
        return i;
    }
    else if(i==arr.size()){
        return -1;
    }
    return fo(arr,i+1,target);
}
int lo(vector<int> arr,int i,int target){
     if(i==arr.size()){
        return -1;
     }
     int idx=lo(arr,i+1,target);
     if(idx==-1 && arr[i]==target){
            return i;
     }
     return idx;
}
int main(){
    vector <int> arr={1,2,3,3,3,4};
    int target=3;
    cout<<"Index:"<<fo(arr,0,target);
    cout<<"\n Index:"<<lo(arr,0,target);
    return 0;
}