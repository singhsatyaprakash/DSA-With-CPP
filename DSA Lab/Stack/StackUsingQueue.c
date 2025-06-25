/*Problem Statement 16-
Design an algorithm	and	write a	program	to implement stack operations using	minimum	number of queues.
Name:Satya Prakash Singh
Section:A1
Roll No:61
Course:B.Tech(CSE)
*/ 

#include<stdio.h>
void enqueue(int q[], int *f, int *r, int v,int n) {
     if (*r == n - 1) {
       printf("Queue is full\n");
    return;
   } 
    else{
      if(*f==-1){
        *f=0;
     }
    q[++(*r)] = v;
    }
}

int dequeue(int q[], int *f, int *r) {
  if (*f == -1)
   {
   printf("Queue is empty\n");
   return -1; 
   } 
   else{
     int t = q[*f];
     (*f)++;
       if (*f > *r){
           *f = -1;
           *r = -1;
          }
   return t;
   }
}

void display(int q[],int f,int r){
    if(f==-1){
      printf("Queue is empty\n");
      return;
     }
    for(int i = f; i <= r; i++){
       printf("%d  ",q[i]);
     }
printf("\n");
}

void push(int q1[], int *f1, int *r1,int x,int n){
    if(*r1==n-1){
      printf("Stack is full\n");
      return;
     }
   enqueue(q1, f1, r1, x,n); 
}

int pop(int q1[],int q2[],int *f1,int *f2,int *r1,int *r2,int n){
     if(*f1 == -1){
      printf("Stack is empty\n");
      return -1; 
     } 
     else{
       while(*f1 != *r1){
           int t=dequeue(q1,f1,r1);
           enqueue(q2,f2,r2,t,n);
         }
       int p= dequeue(q1, f1, r1);
      while(*f2 != -1){
           int t=dequeue(q2,f2,r2);
           enqueue(q1,f1,r1,t,n);
        }
    return p;
}
}

int main() {
    int n;
    printf("Enter size of stack : ");
    scanf("%d",&n);
    int q1[n], q2[n];
    int f1 = -1, f2 = -1, r1 = -1, r2 = -1;
    printf("Press[1] to push an element\n");
    printf("Press[2] to pop an element\n");
    printf("Press[3] to display\n");
    printf("Press[0] to Exit.\n");
    int choice;
    int exit;
    do{
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int val;
                printf("Enter element to push :");
                scanf("%d",&val);
                push(q1, &f1, &r1, val,n);
                break;
            }
            case 2:{
                int k= pop(q1,q2, &f1,&f2, &r1,&r2,n);
                printf("Deleted Element : %d",k);
                 printf("\nStack after pop: ");
                 display(q1, f1, r1);
                break;
            }
            case 3:{
                 printf("Stack: ");
                 display(q1, f1, r1);
                 break;
            }
            case 0:{
                printf("Exit.\n");
            }
            default:
            printf("Invalid Choice!!!\n");
        }
    }while(choice!=0);
    return 0;
}