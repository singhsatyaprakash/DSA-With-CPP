#include<stdio.h>
#include<stdlib.h>
int *declaration(){
    int *ptr;
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int arr[n];
    //allocated memory in stack..
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }
    // ptr=&arr[0];
    return ptr;
}

int main(){
    int *ptr;
    ptr=declaration();
    int n=sizeof(ptr)/sizeof(int);
    for(int i=0;i<n;i++){
        printf("%u ",ptr[i]);
    }
    return 0;
}