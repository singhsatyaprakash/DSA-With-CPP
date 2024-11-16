#include<iostream>
#include<unordered_map>
using namespace std;
void pairSum(int arr[],int n,int target){
    unordered_map<int,int>m;
    int flag=0;
    for(int i=0;i<n;i++){
        int comp=target-arr[i];
        if(m.count(comp)){//search in map
            cout<<"Pair sum idx are: "<<m[comp]<<" & "<<i<<endl;
            flag=1;
            break;
        }
        //add to map
        m[arr[i]]=i;
    }
    if(flag==0){
        printf("Not possible to achieve PairSum.");
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
    int target;
    cout<<"Enter target to Pairsum:";
    cin>>target;
    pairSum(arr,n,target);
    return 0;
}