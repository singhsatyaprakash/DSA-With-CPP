/*Push is costly and pop is optimal...*/
#include <iostream>
#include <queue>
using namespace std;
queue<int>q1,q2;

void pushCostly(int x) {
    q2.push(x);
    //dequeue all elements from q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    // Swap q1 and q2
    queue<int>temp;
    temp=q1;
    q1=q2;
    q2=temp;
}
int popOptimal() {
    int t;
    if (q1.empty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }else{
    t=q1.front();
    q1.pop();
    return t;
    }
}
void display(){
    queue<int>temp;//to save queuee
    temp=q1;
    while(!temp.empty()){
        cout<<temp.front()<<" ";
        temp.pop();
    }
    cout<<endl;
}
int main() {
    pushCostly(10);
    pushCostly(12);
    pushCostly(7);
    cout<<"Stack is:";
    display();
    cout<<"Pop element is:"<<popOptimal()<<endl;
    pushCostly(8);
    pushCostly(-9);
    cout<<"Pop element is:"<<popOptimal()<<endl;
    cout<<"Stack is:";
    display();
    return 0;
}
