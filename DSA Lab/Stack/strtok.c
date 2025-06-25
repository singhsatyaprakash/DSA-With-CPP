// C program to illustrate the use of strtok() in C
#include <stdio.h>
#include <string.h>
 
int main()
{
 
    // Original string
    char str[] = "GEEKS-FOR-GEEKS";
 
    // Space is used as the delimiter to split
    char delimiter[] = "-";
 
    // Declare empty string to store token
    char* token;
 
    printf("Initial String: %s", str);
    printf("\nAfter Tokenization: \n");
    // Get the first token
    token = strtok(str, delimiter);
 
    // using loop to get the rest of the token
    while (token) {
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
    }
 
    return 0;
}