#include<iostream>
#include<stack>
using namespace std;
void pushAtBottom(stack<int>&st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int temp=st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(temp);//backtracking
}
void display(stack<int> st){
    cout<<"Stack:";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    stack<int>st;
    //creating stack
    st.push(11);
    st.push(12);
    st.push(13);
    st.push(14);
    display(st);
    pushAtBottom(st,10);
    display(st);//call by value
    return 0;
}