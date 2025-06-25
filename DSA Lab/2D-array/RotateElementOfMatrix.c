/*
Problem Staement III:Given a matrix of size n X n containing positive integers, write an algorithm and a program to
rotate the elements of matrix in clockwise direction.
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include <stdio.h>
void rotateSpiral(int n,int matrix[n][n]){
    int startRow=0,endRow=n-1;
    int startCol=0,endCol=n-1;
    while(startRow<endRow && startCol<endCol){
        int prev=matrix[startRow+1][startCol];
        // Move elements of the top row to the right
        for(int i=startCol;i<=endCol;i++) {
            int temp=matrix[startRow][i];
            matrix[startRow][i]=prev;
            prev=temp;
        }
        startRow++;
        // Move elements of the last column down
        for(int i=startRow;i<=endRow;i++){
            int temp=matrix[i][endCol];
            matrix[i][endCol]=prev;
            prev=temp;
        }
        endCol--;
        // Move elements of the bottom row to the left
        if(startRow<=endRow){
            for(int i=endCol;i>=startCol;i--){
                int temp=matrix[endRow][i];
                matrix[endRow][i]=prev;
                prev=temp;
            }
        }
        endRow--;
        // Move elements of the first column up
        if(startCol<=endCol){
            for(int i=endRow;i>=startRow;i--){
                int temp=matrix[i][startCol];
                matrix[i][startCol]=prev;
                prev=temp;
            }
        }
        startCol++;
    }
}

void printMatrix(int n,int matrix[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n;
    printf("Enter size of matrix:");
    scanf("%d",&n);
    int matrix[n][n];
    printf("Enter matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    rotateSpiral(n,matrix);
    printf("Rotated Matrix:\n");
    printMatrix(n,matrix);
    return 0;
}