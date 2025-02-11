#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int binarySearch(vector<int>arr,int key){
    int si=0,ei=arr.size()-1;
    while(si<=ei){
        int mid=si+(ei-si)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(key<arr[mid]){
            ei=mid-1;
        }
        else{
            si=mid+1;
        }
    }
    return -1;
}
int main(){
    cout<<"Enter n:";
    int n,val;
    cin>>n;
    vector<int>arr;
    cout<<"Enter element:"<<endl;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    int key;
    cout<<"Enter key to search:";
    cin>>key;
    sort(arr.begin(),arr.end());
    int idx=binarySearch(arr,key);
    if(idx!=-1){
        cout<<key<<" present at index "<<idx<<"."<<endl;
    }
    else{
        cout<<"Not present."<<endl;
    }
    return 0;

}