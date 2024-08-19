#include<iostream>
using namespace std;
void printIndex(int arr[],int n,int i,int target){

    if(arr[i]==target){
        cout<<i<<" ";
    }
    if(i==n-1){
        return;
    }
    return printIndex(arr,n,i+1,target);
}
int main(){
    int n;
	cout<<"Enter size of array:";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of sorted array(Binary Search):\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int target;
	cout<<"Enter element to search:";
	cin>>target;
    printIndex(arr,n,0,target);
    return 0;
}