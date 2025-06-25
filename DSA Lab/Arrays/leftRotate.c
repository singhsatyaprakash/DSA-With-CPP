/*1. Given an array of integers, write an algorithm and a program to left rotate the array by specific number of elements.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
void reverse(int arr[],int n,int i,int j){
       while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
void leftRotate(int arr[],int n, int k){
    k=k%n;
    //reverse upto k times  firstly occur elements in array.
    reverse(arr,n,0,k-1);
    //reversing remaining elements of array...
    reverse(arr,n,k,n-1);
    //reversing whole array....
    reverse(arr,n,0,n-1);
}

int main(){
    int n,k;
    printf("Enter no. of elements in array:");
    scanf("%d",&n);
    //reading elements of array...
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //reading how many times to rotate...
    printf("Enter how many time left rotate the array:");
    scanf("%d",&k);
    leftRotate(arr,n,k);
    printf("Rotated array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
//OUTPUT:
/*
Enter no. of elements in array:15
Enter the elements:
-2 8 7 1 2 6 8 9 0 2 -6 2 9 7 1
Enter how many time left rotate the array:6
Rotated array:8 9 0 2 -6 2 9 7 1 -2 8 7 1 2 6

Enter no. of elements in array:10
Enter the elements:
1 6 3 2 9 1 4 2 3 6
Enter how many time left rotate the array:4
Rotated array:9 1 4 2 3 6 1 6 3 2

Enter no. of elements in array:5
Enter the elements:
2 4 -3 2 3
Enter how many time left rotate the array:3
Rotated array:2 3 2 4 -3
*/
