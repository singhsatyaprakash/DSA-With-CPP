#include<iostream>
using namespace std;
int BinarySearch(int arr[],int low,int high,int target){
	if(high<low){
		return -1;
	}
	int mid=low+(high-low)/2;
	if(arr[mid]==target){
		return mid;
	}
	
	if(arr[mid]>target){
		
		return BinarySearch(arr,low,mid-1,target);
	}
	else if(arr[mid]<target){
		return BinarySearch(arr,mid+1,high,target);
	}
	
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
	int res=BinarySearch(arr,0,n-1,target);
	cout<<"Index:"<<res;
	return 0;
}