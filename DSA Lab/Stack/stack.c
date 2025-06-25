/*
Problem Statement I. Design an algorithm and a program to implement stack using array. The program should
implement following stack operations:
a) Create() - create an empty stack
b) Push(k) - push an element k into the stack
c) Pop() - pop an element from the stack snd return it
d) IsEmpty() - check if stack is empty or not
e) Size() - finds the size of the stack
f) Print() - prints the contents of stack
Name:Satya Prakash Singh
Section:A1
Roll No.:61
Course:B.Tech(C.S.E)
*/
#include<stdio.h>
#include<stdbool.h>
void pushElement(int arr[],int value,int n,int *top){
	if(*top==n-1){
		printf("Stack is overflow\n");
	}
	else{
	arr[++(*top)]=value;
	}
}
int popElement(int arr[],int *top){
	int k;
	if(*top==-1){
		printf("Stack is underflow\n");
		return -1;
	}
	else{
	
		k=arr[*top];
		(*top)--;
	}
	return k;
}
bool isEmpty(int *top){
	if(*top==-1){
	return true;
	}
	else{
	return false;
	}
}
void printStack(int arr[],int *top){
	for(int i=0;i<=(*top);i++){
	    printf("%d ",arr[i]);
	}
    printf("\n");
}
int main(){
	int n,m,choice;
	printf("Enter size of stack:");
	scanf("%d",&n);
	int arr[n];
	int top=-1;
do{

	printf("Press[1] for push in stack\n");
	printf("Press[2] for pop out in stack\n");
	printf("Press[3] for isEmpty stack\n");
	printf("Press[4] for size of stack\n");
	printf("Press[5] for print stack\n");
printf("Enter:");
scanf("%d",&m);
switch(m){
	case 1:{
	int value;
	printf("Enter element to push:");
	scanf("%d",&value);
	pushElement(arr,value,n,&top);
	break;
	}
	case 2:{
	 int p=popElement(arr,&top);
	 if(p!=-1){
	 printf("Pop element is:%d\n",p);
	 break;
	}
	}
	case 3:{
	bool emp=isEmpty(&top);
	if(emp){
	printf("Stack is Empty\n");
	}
	else{
	printf("Stack is not empty\n");
	}
	break;
	}
	case 4:{
	 printf("Size of stack is:%d\n",n);
	 break;
	 }
	 case 5:{
	 printStack(arr,&top);
	 break;
	 }
	 default:
	 printf("Invaild option");
}
printf("Press 1 to continue  0 to exit: ");
scanf("%d",&choice);
} while(choice!=0);

return 0;
}