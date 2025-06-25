/*Given an array of nonnegative integers, where all numbers occur even number of times except one number which occurs odd number of times. Write an algorithm and a program to find this number. (Time complexity = O(n))
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
int main(){
    int n;
    printf("Enter no. of elements in array:");
    scanf("%d",&n);
    //reading elements of array...
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //using bitwise operator XOR...
    int XORsum=0;
    for(int i=0;i<n;i++){
        XORsum^=arr[i];
    }
    if(XORsum==0){
        printf("No such element present.");
    }
    else{
    printf("Output:%d",XORsum);
    }
    return 0;
}



/*//Alternative
#include<stdio.h>
int main(){
    int n;
    printf("Enter no. of elements in array:");
    scanf("%d",&n);
    //reading elements of array...
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //finding max element of array...
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    //a frequency array to store the count of number appears in array...
    int freq[max+1];//one extra because 0 is also a index in array...
    for(int i=0;i<max+1;i++){
        //initalising all element to 0...
        freq[i]=0;
    }
    //travesing array to count...
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    //checking odd occurance...
    for(int i=0;i<max+1;i++){
        if(freq[i]%2!=0){
            printf("Output:%d",i);
        }
    }
    return 0;
}*/