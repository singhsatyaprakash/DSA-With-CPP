#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int>vec;
public:
    void push(int val){
        vec.push_back(val);
    }
    void pop(){
        if(vec.size()==0){
            cout<<"Stack is empty."<<endl;
            return;
        }
        vec.pop_back();
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty."<<endl;
            return -1;
        }else{
        int topIdx=vec.size()-1;
        return vec[topIdx];
        }
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};
int main(){
    Stack s;
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    cout<<"Top:"<<s.top()<<endl;;
    s.pop();
    cout<<"Top:"<<s.top()<<endl;;
    s.pop();
    cout<<"Top:"<<s.top()<<endl;;
    s.pop();
    cout<<"Top:"<<s.top()<<endl;;
    s.pop();
    s.pop();
    return 0;
}