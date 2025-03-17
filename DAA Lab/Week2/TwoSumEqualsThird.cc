/* Given a sorted array of positive integers, design an algorithm and implement it using a program
 to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void twoSumEqualsThird(vector<int>arr){
    int n=arr.size();
    int flag=0;
    for(int k=n-1;k>=2;k--){
        int i=0,j=k-1;
        while(i<j){
            if(arr[i]+arr[j]==arr[k]){
                cout<<"Sequence:";
                cout<<i+1<<", "<<j+1<<", "<<k+1<<endl;
                flag=1;
                break;
            }
            else if(arr[i]+arr[j]<arr[k]){
                i++;
            }
            else{
                j--;
            }
        }
    }
    if(flag==0){
        cout<<"No Sequence found."<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int>arr;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    sort(arr.begin(),arr.end());
    twoSumEqualsThird(arr);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE3(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}