#include<stdio.h>
int findRowHaveMax1(int m,int n,int arr[m][n]){
    int i=0,j=n-1;
    while(i<m && j>=0){
        if(arr[i][j]==1){
            j--;
        }
        else{
            i++;
        }
    }
    return i+1;
}
int main(){
    // reading matrix...
    int m,n;
    printf("Enter size of matrix:");
    scanf("%d%d",&m,&n);
    int arr[m][n];
    printf("Enter elements of matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int max1Row=findRowHaveMax1(m,n,arr);//calling function...
    printf("Row having maxiumum 1 is row-->%d",max1Row);
    return 0;
}