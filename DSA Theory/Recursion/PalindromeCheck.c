/*
Palindrome Check
Write a program using recursion function that checks if a given string is a
palindrome (reads the same forwards and backwards).
Example:
is_palindrome("racecar") = true
is_palindrome("hello") = false
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool is_palindrome(char str[],int si,int ei){
    if(si>=ei){
        return true;
    }
    if(str[si]!=str[ei]){
        return false;
    }
    return is_palindrome(str,si+1,ei-1);
}
int main(){
    char str[100];
    printf("Enter String:");
    scanf("%[^\n]s",str);
    int n=strlen(str);
    if(is_palindrome(str,0,n-1)){
        printf("Given string is Palindrome.\n");
    }
    else{
        printf("Given string is NOT Palindrome.\n");
    }
    return 0;
}