#include <iostream>
using namespace std;
void push(int q1[], int q2[], int *rear1, int *rear2, int *front1, int front2, int x) {
    q2[++(*rear2)] = x;
    while (*rear1 >= 0) {
        q2[++(*rear2)] = q1[(*rear1)--];
    }
    int temp[100];
    int j = 0;
    for (int i = *rear2;i>=0;i--) {
        temp[j++]=q2[i];
    }
    for (int i=0;i<j;i++) {
        q1[i]=temp[i];
    }
    *rear1=j-1;
    *rear2=-1;
}

int pop(int q1[], int *rear1) {
    if (*rear1 == -1) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return q1[(*rear1)--];
}

void display(int q1[], int rear1) {
    if (rear1 == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
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

    push(q1, q2, &rear1, &rear2, &front1, front2, 10);
    push(q1, q2, &rear1, &rear2, &front1, front2, 12);
    push(q1, q2, &rear1, &rear2, &front1, front2, 17);
    display(q1, rear1);
    cout << "The popped element is " << pop(q1, &rear1) << endl;
    push(q1, q2, &rear1, &rear2, &front1, front2, 8);
    cout << "The popped element is " << pop(q1, &rear1) << endl;
    display(q1, rear1);
    return 0;
}