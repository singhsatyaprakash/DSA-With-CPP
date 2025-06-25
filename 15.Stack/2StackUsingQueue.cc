#include <iostream>
using namespace std;
void push(int q1[], int x, int *front1, int *rear1) {
    if (*front1 == -1) {
     *front1 = 0;
    }
    q1[++(*rear1)] = x;
}
int pop(int q1[], int q2[], int *rear1, int *rear2, int *front2,int *front1) {
    if (*rear1 == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    int x = q1[*rear1];
    int i;
   for(i=0;i<*rear1-1;i++){
        q2[++(*rear2)]=q1[(*front1)++];
   }
 (*rear1)--;
 for(i=0;i<*rear1;i++){
     int temp=q1[i];
     q1[i]=q2[i];
     q2[i]=temp;
 }
    return x;
}
void display(int rear1, int q1[]) {
    for (int i = 0; i <= rear1; i++) {
        cout << q1[i] << " ";
    }
    cout << endl;
}

int main() {
    int q1[100], q2[100];
    int front1, rear1, front2, rear2;
    front1 = rear1 = -1;
    front2 = rear2 = -1;
    push(q1, 8, &front1, &rear1);
    push(q1, 10, &front1, &rear1);
    push(q1, 12, &front1, &rear1);
    display(rear1, q1);
    cout << "poped element is " << pop(q1, q2, &rear1, &rear2,&front2,&front1) << endl;
    push(q1, -9, &front1, &rear1);
    cout << "poped element is " << pop(q1, q2, &rear1, &rear2,&front2,&front1) << endl;
    display(rear1, q1);
    return 0;
}