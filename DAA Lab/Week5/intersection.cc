/*You have been given two sorted integer arrays of size m and n. Design an algorithm and
 implement it using a program to find list of elements which are common to both. (Time
 Complexity = O(m+n))*/
#include<iostream>
#include<vector>
using namespace std;
void intersection(int arr1[],int arr2[],int m,int n){
    int i=0,j=0;
    vector<int>temp;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }
        else if(arr1[i]==arr2[j]){
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    cout<<"Common element:"<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
}
int main(){
    int m,n;
    cout<<"Enter size of 1st array:";
    cin>>m;
    int arr1[m];
    cout<<"Enter element:";
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    cout<<"Enter size of 2nd array:";
    cin>>n;
    int arr2[n];
    cout<<"Enter element:";
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    intersection(arr1,arr2,m,n);
    cout<<"\n****************************************************************************"<<endl;
    cout<<"Prepared and Executed By:Satya Prakash Singh  CSE4(A1)  ClassRollNo:61"<<endl;
    cout<<"****************************************************************************"<<endl;
    return 0;
}