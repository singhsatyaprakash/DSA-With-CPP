#include<stdio.h>
#include<stdlib.h>
int *declaration(){
    int *ptr;
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    ptr=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
    }

    return ptr;
}

int main(){
    int *ptr;
    ptr=declaration();
    int n=sizeof(ptr)/sizeof(int);
    // int n=sizeof(ptr);
    for(int i=0;i<n;i++){
        printf("%u ",ptr[i]);
    }
    return 0;
}