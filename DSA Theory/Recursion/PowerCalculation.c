/*
2. Power Calculation
Write a program using recursion function to calculate x^n (x raised to the power
of n).
Example:
power(2, 3) = 2^3 = 8
*/
#include<stdio.h>
int PowerCalculation(int x,int n){
    if(n==0){
        return 1;
    }
    int prod=PowerCalculation(x,n/2);
    if(n%2==0){//even power
        return prod*prod;
    }
    else{
        return x*prod*prod;
    }
}
int main(){
    int x,n;
    printf("Enter Base:");
    scanf("%d",&x);
    printf("Enter power:");
    scanf("%d",&n);
    int res=PowerCalculation(x,n);
    printf("%d raise to power %d = %d",x,n,res);
    return 0;
}