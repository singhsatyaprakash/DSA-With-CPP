/*Q:WACP to reverse an array of 10 elements which are predefined int the main function,without using any extra space.*/
#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(int);

    //two pointer approach...
    int i=0,j=n-1;
    while(i<=j){
        //swaping
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        //updatinq pointer to reach towards each other...
        i++;
        j--;
    }
    printf("Reverse array:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}