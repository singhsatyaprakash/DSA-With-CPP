#include<iostream>
#include<deque>
using namespace std;
void printDq(deque<int>dq){
    for(auto i:dq){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    deque<int>dq;
    dq.push_back(1);
    dq.push_front(2);
    //all vector function apply here
    printDq(dq);
    dq.pop_front();
    printDq(dq);
}