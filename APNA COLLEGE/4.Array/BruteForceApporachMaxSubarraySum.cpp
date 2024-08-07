#include<iostream>
#include<climits> 
using namespace std;
void printarraysub(int *arr,int n){
    int maxSum =INT_MIN;   
        for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            maxSum=max(maxSum,sum);
            }
            cout<<sum<<", ";
            maxSum=max(maxSum,sum);
        }
        cout<<endl;
    }
    cout<<"Maximum sum subarray:"<<maxSum;
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //printing subarrays...
    printarraysub(arr,n);
    return 0;
}