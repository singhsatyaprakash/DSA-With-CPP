/*II. Given an unsorted array of integers and two numbers a and b. Design an algorithm and write a program to find minimum distance between a and b in this array. Minimum distance between any two numbers a and b present in array is the minimum difference between their indices.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdlib.h>
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
    int a,b,mindiff=n-1;
    printf("Enter a:");
    scanf("%d",&a);
    printf("Enter b:");
    scanf("%d",&b);
    int pos_a=-1,pos_b=-1;
    //traversing array...
    for(int i=0;i<n;i++){
        //finding position...
        if(arr[i]==a){
            pos_a=i;
        }
        if(arr[i]==b){
            pos_b=i;
        }
        if(pos_a!=-1 && pos_b!=-1){
            int diff=abs(pos_a-pos_b);//use to make number positive...
            if(diff<mindiff){
                mindiff=diff;
            }
        }
    }
    if(pos_a==-1 || pos_b==-1){
        printf("Minimum Distance is:%d\n",-1);
    }
    else{
        printf("Minimum Distance is:%d\n",mindiff);
    }
    return 0;
}