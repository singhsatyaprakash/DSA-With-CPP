/*
Sum of Digits
Write a program using recursion function that returns the sum of the digits of a
given number n.
Example:
sum_of_digits(1234) = 1 + 2 + 3 + 4 = 10
*/
#include<stdio.h>
int sum_of_digits(int num){
    if(num==0){
        return 0;
    }
    int temp=num%10;
    num=num/10;
    return temp+sum_of_digits(num);
}
int main(){
    int num;
    printf("Enter Number:");
    scanf("%d",&num);
    int res=sum_of_digits(num);
    printf("Sum of digit of given number = %d",res);
    return 0;
}