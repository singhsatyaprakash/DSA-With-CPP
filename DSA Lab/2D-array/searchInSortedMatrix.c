/*Given a matrix of order n x n where every row and every column is sorted in asscending order.WACP to find wheather a element 'k' is present in matrix or not.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdbool.h>
bool searchElement(int n,int k ,int arr[][n]){
    int i=0,j=n-1;
    while(i<=n-1 && j>=0){
    if(arr[i][j]==k){
        return true;
    }
    else if(arr[i][j]>k){
        j--;
    }
    else if(arr[i][j]<k){
        i++;
    }
    }
    return false;
}
int main(){
    // reading matrix...
    int n;
    printf("Enter size of matrix:");
    scanf("%d",&n);
    int arr[n][n];
    printf("Enter elements of matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    //scaning element to search...
    int k;
    printf("Enter eleement to search:");
    scanf("%d",&k);
    //callig function to search..
    bool res=searchElement(n,k,arr);//pass 2D array...
    if(res){
        printf("Present");
    }
    else{
        printf("NOT Present");
    }
    return 0;
}