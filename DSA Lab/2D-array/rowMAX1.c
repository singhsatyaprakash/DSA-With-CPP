/*Problem Statement II. Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
algorithm and a program to find which row has maximum number of 1's. (Linear time
complexity)
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
  #include<stdlib.h>
  int MaxRow(int arr[][50],int m,int n){
    int i=0; //row
    int j=n-1; //columns
    int maxrow=-1;
    while(i<m && j>=0){
        if(arr[i][j]==1){
        maxrow=i;
            j--;
        }
        else{
            i++;
        }
    }
    return maxrow; 
  }
  int main(){
    int m,n;
    printf("Enter the size of m &n: ");
    scanf("%d%d",&m,&n);
    
int arr[50][50];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
   int result = MaxRow(arr,m,n);
    if (result != -1)
        printf("Row with maximum 1's is: %d\n", result+1);
    else
        printf("No row contains 1's\n");
    return 0;
  }