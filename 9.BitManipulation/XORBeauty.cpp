#include<iostream>
using namespace std;
int BeautyofXOR(int *num,int i,int j,int k){
    int res=(num[i]|num[j]&num[k]);
    return res;
}
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array:";
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int i,j,k;
    cout<<"Enter indicies:(0<=i,j,k<n):";
    cin>>i,j,k
    int res=BeautyofXOR(arr,i,j,k);
    cout<<res<<endl;
    return 0;
}