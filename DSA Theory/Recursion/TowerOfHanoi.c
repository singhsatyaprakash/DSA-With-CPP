/*
4. Tower of Hanoi
Implement the Tower of Hanoi problem using recursion. The function should
output the steps required to move n disks from one peg to another, using a third
peg as an auxiliary.
Example (with 3 disks):
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/
#include<stdio.h>
void toh(int n ,char from,char to,char aux){
    static int step=1;
    if(n==0)
    return;
    toh(n-1,from,aux,to);
    printf("Step %d: Move disk %c to %c\n",step++,from,to);
    toh(n-1,aux,to,from); 
}
int main(){
    int n;
    printf("How many disk:");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}