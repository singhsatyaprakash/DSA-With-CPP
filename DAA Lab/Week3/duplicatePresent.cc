/*. Given an unsorted array of positive integers, design an algorithm and implement it using a
 program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
 Complexity = O(n log n))
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isDuplicate(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(arr[i-1]==arr[i]){
            return true;
        }
    }
    return false;
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
    if(isDuplicate(arr)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}