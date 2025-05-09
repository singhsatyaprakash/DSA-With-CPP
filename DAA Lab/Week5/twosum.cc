/*Given an unsorted array of integers, design an algorithm and implement it using a program to
 find whether two elements exist such that their sum is equal to the given key element. (Time
 Complexity = O(n log n))*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void twoSum(vector<int>arr,int key){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int i=0,j=n-1;
    bool flag=false;
    while(i<j){
        if(arr[i]+arr[j]==key){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            flag=true;
            break; 
        }
        else if(arr[i]+arr[j]<key){
            i++;
        }
        else{
            j--;
        }
    }
    if(!flag){
        cout<<"NO such element exists."<<endl;
    }
}
int main(){
    int n,val;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    int key;
    cout<<"Enter key:";
    cin>>key;
    twoSum(arr,key);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE4(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}