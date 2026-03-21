#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<int,int>map;
    
    int l=0,r=0;
    int sum=0;
    int ansSum=0;
    while(r<n){
        sum+=arr[r];
        map[arr[r]]++;
        while(map.size()>k){
            sum-=arr[l];
            map[arr[l]]--;
            if(map[arr[l]]==0){
                map.erase(arr[l]);
            }
            l++;
        }
        ansSum=max(ansSum,sum);
        //kadanes algo...
        if(sum < 0){
            map.clear();
            sum = 0;
            l = r+1;
        }
        r++;
    }
    cout<<"GoodSubarray sum:"<<ansSum<<endl;

}