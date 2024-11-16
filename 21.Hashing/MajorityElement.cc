/*Find the element that appears more than n/3 times..*/
#include<iostream>
#include<unordered_map>
using namespace std;
void MostFrequent(int arr[],int n){
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        if(m.count(arr[i])){//if found increment the count
            m[arr[i]]++;
        }
        else{//add to map
            m[arr[i]]=1;
        }
    }
    for(pair<int,int>el:m){
        if(el.second>n/3){
            cout<<"Element "<<el.first<<" occurs "<< el.second <<" times"<<endl;
        }
    }
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MostFrequent(arr,n);
    return 0;
}