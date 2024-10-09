#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int>vec;
public:
    void push(int val){
        //1.insert
        vec.push_back(val);
        //2.Fix heap
        int x=vec.size()-1;//inex of child..
        int parI=(x-2)/2;
        while(parI>=0 && vec[x]>vec[parI]){
            swap(vec[parI],vec[x]);
            x=parI;
            parI=(x-2)/2;
        }
    }
    void pop(){

    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(12);
    heap.push(120);
    heap.push(10);
    heap.push(100);
    cout<<"Top:"<<heap.top()<<endl;
    return 0;
}