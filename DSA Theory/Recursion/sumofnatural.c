#include<stdio.h>
int sumOfNaturalNum(int n){
    if(n==0){
        return 0;
    }
    return n+sumOfNaturalNum(n-1);
}
int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int sum;
    sum=sumOfNaturalNum(n);
    printf("sum=%d",sum);
    return 0;
}