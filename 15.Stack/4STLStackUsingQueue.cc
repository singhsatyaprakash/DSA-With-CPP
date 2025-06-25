#include<iostream>
using namespace std;
#include<queue>
queue<int>q1,q2;
void pushOptimal(int x){
    q1.push(x);
}
int pop(){
    while(q1.size()>1){
        q2.push(q1.front());
        q1.pop();
    }
    int k=q1.front();
    q1.pop();
    swap(q1,q2);
    return k;
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
int main(){
    pushOptimal(8);
    pushOptimal(12);
    pushOptimal(13);
    cout<<"Stack is:";
    display();
    cout<<"Pop element:"<<pop()<<endl;
    pushOptimal(17);
    pushOptimal(-9);
    cout<<"Pop element:"<<pop()<<endl;
    cout<<"Stack is:";
    display();
}