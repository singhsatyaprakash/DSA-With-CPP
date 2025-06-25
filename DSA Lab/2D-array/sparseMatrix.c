#include<stdio.h>
void sparse(int m,int n,int arr[m][n]){
    //counting non zero element...
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                count++;
            }
        }
    }
    //sparse matrix
    int spa[3][count];
    int col=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                spa[0][col]=i;
                spa[1][col]=j;
                spa[2][col]=arr[i][j];
                col++;
            }
        }
    }
    printf("\n");
    // printing sparse matrix...
    for(int i=0;i<3;i++){
        for(int j=0;j<count;j++){
            printf("%d ",spa[i][j]);
        }
        printf("\n");
    }
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
    sparse(m,n,arr);
}