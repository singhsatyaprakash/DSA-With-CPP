#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Stack{
    vector<T>vec;
public:
    void push(T val){
        vec.push_back(val);
    }
    void pop(){
        if(vec.size()==0){
            cout<<"Stack is empty."<<endl;
            return;
        }
        vec.pop_back();
    }
    T top(){
        int topIdx=vec.size()-1;
        return vec[topIdx];
    }
    bool isEmpty(){
        return vec.size()==0;
    }
};
int main(){
    //template...
    //string/ char/ int /float
    Stack<int>  s;
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