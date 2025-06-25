/*
String Reversal
Write a recursive function to reverse a given string.
Example:
reverse_string("hello") = "olleh"
*/
#include<stdio.h>
#include<string.h>
void reverse_string(char str[],int si,int ei){
    if(si>=ei){
        return;
    }
    //swap both index position...
    char temp=str[si];
    str[si]=str[ei];
    str[ei]=temp;
    reverse_string(str,si+1,ei-1);
    return;
}
int main(){
    char str[500];
    printf("Enter String:");
    scanf("%[^\n]s",str);
    int n=strlen(str);
    reverse_string(str,0,n-1);
    printf("Reverse string:%s",str);
    return 0;
}