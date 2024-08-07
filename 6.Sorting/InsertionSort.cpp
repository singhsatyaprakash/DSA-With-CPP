#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    return;
}
int main(){
    int n;
    cout<<"How many elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //insertion sort....
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        //pushing element to its position...
        while(prev>=0 && arr[prev]>curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        }
    cout<<"Sorted array:"<<endl;
       for(int i=0;i<n;i++){ 
        cout<<arr[i]<<" ";
    }

}